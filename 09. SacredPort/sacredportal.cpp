<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

// Constants for game outcomes
const int DRAW = 0;
const int SPIRIT = 1; // Spirit wins
const int SHADOW = 2; // Shadow wins

// Global adjacency list to simplify parameter passing (common CP practice)
vector<vector<int>> realm;
int N;

/**
 * @brief Determines the possible previous states (ancestors) that could have led to 
 * the current state (spirit, shadow, turn).
 */
vector<array<int,3>> get_ancestors(int spirit, int shadow, int turn) {
    vector<array<int,3>> res;
    
    // The previous turn is the opponent's turn.
    int prev_turn = 3 - turn; 

    if (turn == SPIRIT) { 
        // Spirit just moved (s2 -> spirit). Previous turn was Shadow's (prev_turn = 2).
        // Spirit's position changes, Shadow's stays the same.
        for (int s_prev : realm[spirit]) {
            res.push_back({s_prev, shadow, prev_turn});
        }
    } else { 
        // Shadow just moved (h_prev -> shadow). Previous turn was Spirit's (prev_turn = 1).
        // Shadow's position changes, Spirit's stays the same.
        for (int h_prev : realm[shadow]) {
            // Shadow Beast cannot enter the Sacred Portal (node 0)
            if (h_prev > 0) {
                res.push_back({spirit, h_prev, prev_turn});
            }
        }
    }
    return res;
}

void solve() {
    // 1. Read Input
    if (!(cin >> N)) return;
    
    // If graph is too small (needs nodes 0, 1, 2)
    if (N < 3) {
        cout << DRAW << endl;
        return;
    }

    realm.assign(N, vector<int>());
    for (int i = 0; i < N; ++i) {
        int k;
        if (!(cin >> k)) return;

        realm[i].reserve(k);
        for (int j = 0; j < k; ++j) {
            int neighbor;
            if (!(cin >> neighbor)) return;
            realm[i].push_back(neighbor);
        }
    }

    // 2. Initialize Game State Data Structures
    
    // outcome[spirit][shadow][turn] - 0: Draw/Unknown, 1: Spirit Wins, 2: Shadow Wins
    // Turn dimension uses indices 1 (Spirit) and 2 (Shadow).
    vector<vector<vector<int>>> outcome(N, vector<vector<int>>(N, vector<int>(3, DRAW)));
    
    // options[spirit][shadow][turn] - Counts non-losing moves available from this state
    vector<vector<vector<int>>> options(N, vector<vector<int>>(N, vector<int>(3, 0)));

    queue<array<int,4>> q; // {spirit_pos, shadow_pos, turn_just_moved, winner}

    // 3. Pre-calculate total legal moves for each state (options)
    for (int s = 0; s < N; ++s) {
        for (int h = 0; h < N; ++h) {
            // Spirit's turn (turn == 1)
            options[s][h][SPIRIT] = realm[s].size();
            
            // Shadow's turn (turn == 2)
            options[s][h][SHADOW] = realm[h].size();
            
            // Shadow cannot move to node 0, so subtract 1 if 0 is a neighbor.
            for (int neighbor : realm[h]) {
                if (neighbor == 0) {
                    options[s][h][SHADOW]--;
                    break;
                }
            }
        }
    }

    // 4. Initialize Base Cases (Terminal States)
    for (int i = 0; i < N; ++i) {
        for (int turn = 1; turn <= 2; ++turn) {
            // SPIRIT wins: Spirit reaches portal (s=0)
            outcome[0][i][turn] = SPIRIT;
            q.push({0, i, turn, SPIRIT});

            // SHADOW wins: Shadow catches Spirit (s=h, and not at portal 0)
            if (i > 0) { 
                outcome[i][i][turn] = SHADOW;
                q.push({i, i, turn, SHADOW});
            }
        }
    }

    // 5. Retrograde BFS
    while (!q.empty()) {
        auto state = q.front(); q.pop();
        int s = state[0], h = state[1], turn_just_moved = state[2], winner_of_state = state[3];

        // Iterate over all previous states (ancestors)
        for (auto ancestor : get_ancestors(s, h, turn_just_moved)) {
            int s_prev = ancestor[0], h_prev = ancestor[1], t_prev = ancestor[2];
            
            // Check if this ancestor state is still unresolved
            if (outcome[s_prev][h_prev][t_prev] != DRAW) continue;
            
            // Case A: The player whose turn it is now (t_prev) moves to a guaranteed winning state.
            if (winner_of_state == t_prev) {
                outcome[s_prev][h_prev][t_prev] = winner_of_state;
                q.push({s_prev, h_prev, t_prev, winner_of_state});
            } else {
                // Case B: The player (t_prev) moves to a guaranteed losing state (opponent wins).
                
                // Decrement the count of non-losing options for t_prev.
                options[s_prev][h_prev][t_prev]--;
                
                // If all options for t_prev now lead to a loss, the opponent (3-t_prev) wins
                if (options[s_prev][h_prev][t_prev] == 0) {
                    int winner = 3 - t_prev; // The opponent wins
                    outcome[s_prev][h_prev][t_prev] = winner;
                    q.push({s_prev, h_prev, t_prev, winner});
                }
            }
        }
    }

    // 6. Final Result: Start state is (Spirit at 1, Shadow at 2, Spirit moves first (turn 1))
    cout << outcome[1][2][SPIRIT] << endl;
}

int main() {
    // Optimized I/O is standard in CP format
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
=======
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
>>>>>>> cc4f792068bb6026adb91173f7a89889029649cd
