#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sacredPortal(vector<vector<int>>& realm) {
        int N = realm.size();
        const int DRAW = 0, SPIRIT = 1, SHADOW = 2;

        // outcome[spirit][shadow][turn]
        vector<vector<vector<int>>> outcome(50, vector<vector<int>>(50, vector<int>(3, 0)));
        vector<vector<vector<int>>> options(50, vector<vector<int>>(50, vector<int>(3, 0)));

        // options[state] : number of neutral moves from this state
        for (int spirit = 0; spirit < N; ++spirit) {
            for (int shadow = 0; shadow < N; ++shadow) {
                options[spirit][shadow][1] = (int)realm[spirit].size(); // Spirit's turn
                options[spirit][shadow][2] = (int)realm[shadow].size(); // Shadow's turn
                for (int x : realm[shadow]) {
                    if (x == 0) { // Shadow cannot enter portal
                        options[spirit][shadow][2]--;
                        break;
                    }
                }
            }
        }

        queue<array<int,4>> q;

        // Base cases
        for (int i = 0; i < N; ++i) {
            for (int turn = 1; turn <= 2; ++turn) {
                // Spirit reaches portal
                outcome[0][i][turn] = SPIRIT;
                q.push({0, i, turn, SPIRIT});

                // Shadow catches Spirit
                if (i > 0) {
                    outcome[i][i][turn] = SHADOW;
                    q.push({i, i, turn, SHADOW});
                }
            }
        }

        // Retrograde BFS
        while (!q.empty()) {
            auto state = q.front(); q.pop();
            int spirit = state[0], shadow = state[1], turn = state[2], result = state[3];

            for (auto ancestor : ancestors(realm, spirit, shadow, turn)) {
                int s2 = ancestor[0], sh2 = ancestor[1], t2 = ancestor[2];
                if (outcome[s2][sh2][t2] == DRAW) {
                    if (t2 == result) {
                        outcome[s2][sh2][t2] = result;
                        q.push({s2, sh2, t2, result});
                    } else {
                        options[s2][sh2][t2]--;
                        if (options[s2][sh2][t2] == 0) {
                            outcome[s2][sh2][t2] = 3 - t2; // other side wins
                            q.push({s2, sh2, t2, 3 - t2});
                        }
                    }
                }
            }
        }

        // Start: Spirit at 1, Shadow at 2, Spirit moves first
        return outcome[1][2][1];
    }

private:
    // Possible ancestors of a state
    vector<array<int,3>> ancestors(const vector<vector<int>>& realm, int spirit, int shadow, int turn) {
        vector<array<int,3>> res;
        if (turn == 2) { // Shadow just moved -> Spirit turn before
            for (int s2 : realm[spirit]) {
                res.push_back({s2, shadow, 3 - turn});
            }
        } else { // Spirit just moved -> Shadow turn before
            for (int sh2 : realm[shadow]) {
                if (sh2 > 0) { // Shadow cannot go into portal
                    res.push_back({spirit, sh2, 3 - turn});
                }
            }
        }
        return res;
    }
};
