#include <bits/stdc++.h>
using namespace std;

enum class State { Draw, LightWin, ShadowWin };

class Solution {
public:
    int sacredPortalGame(vector<vector<int>>& graph) {
        int n = graph.size();

        // states[shadow][light][turn]
        // turn = 0 (Light's turn), 1 (Shadow's turn)
        vector<vector<vector<State>>> states(
            n, vector<vector<State>>(n, vector<State>(2, State::Draw)));

        vector<vector<vector<int>>> outDegree(
            n, vector<vector<int>>(n, vector<int>(2, 0)));

        queue<tuple<int, int, int, State>> q;

        // Count moves possible
        for (int shadow = 0; shadow < n; ++shadow) {
            for (int light = 0; light < n; ++light) {
                // Light moves from its graph
                outDegree[shadow][light][0] = graph[light].size();

                // Shadow moves, but never into 0
                int cnt = 0;
                for (int nb : graph[shadow])
                    if (nb != 0) cnt++;
                outDegree[shadow][light][1] = cnt;
            }
        }

        // Base winning conditions
        for (int shadow = 1; shadow < n; ++shadow) {
            for (int turn = 0; turn < 2; ++turn) {
                states[shadow][0][turn] = State::LightWin;
                q.emplace(shadow, 0, turn, State::LightWin);

                states[shadow][shadow][turn] = State::ShadowWin;
                q.emplace(shadow, shadow, turn, State::ShadowWin);
            }
        }

        // Reverse BFS to deduce outcomes
        while (!q.empty()) {
            int shadow, light, turn;
            State state;
            tie(shadow, light, turn, state) = q.front();
            q.pop();

            if (shadow == 2 && light == 1 && turn == 0) {
                if (state == State::LightWin) return 1;
                if (state == State::ShadowWin) return 2;
                return 0;
            }

            int prevTurn = turn ^ 1;

            const vector<int>& prevList = (prevTurn == 1 ? graph[shadow] : graph[light]);
            for (int prev : prevList) {
                int prevShadow = (prevTurn == 1 ? prev : shadow);
                int prevLight  = (prevTurn == 1 ? light : prev);

                if (prevShadow == 0) continue;
                if (states[prevShadow][prevLight][prevTurn] != State::Draw) continue;

                bool canWin =
                    (prevTurn == 0 && state == State::LightWin) ||
                    (prevTurn == 1 && state == State::ShadowWin);

                if (canWin || --outDegree[prevShadow][prevLight][prevTurn] == 0) {
                    states[prevShadow][prevLight][prevTurn] = state;
                    q.emplace(prevShadow, prevLight, prevTurn, state);
                }
            }
        }

        return 0;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        graph[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> graph[i][j];
        }
    }

    Solution s;
    cout << s.sacredPortalGame(graph) << endl;
    return 0;
}
