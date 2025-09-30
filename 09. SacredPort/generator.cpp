#include "../testlib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>
#include <set>

using namespace std;

// --- SOLUTION LOGIC FOR OUTPUT CALCULATION ---

// Constants for game outcomes
const int DRAW = 0;
const int SPIRIT = 1; // Light Spirit wins
const int SHADOW = 2; // Shadow Beast wins

// Global structures needed by the solution logic
int N_GLOBAL;
vector<vector<int>> REALM_GLOBAL;

// Data structures for the Retrograde BFS solution logic
vector<vector<vector<int>>> outcome;
vector<vector<vector<int>>> options;
queue<array<int, 4>> q; // {spirit_pos, shadow_pos, turn_just_moved, winner}

/**
 * @brief Determines the possible previous states (ancestors) that could have led to 
 * the current state.
 */
vector<array<int, 3>> get_ancestors(int spirit, int shadow, int turn_just_moved) {
    vector<array<int, 3>> res;
    int prev_turn = 3 - turn_just_moved; 

    if (turn_just_moved == SPIRIT) { 
        // Ancestor moved from s_prev to spirit, Shadow was stationary.
        for (int s_prev : REALM_GLOBAL[spirit]) {
            res.push_back({s_prev, shadow, prev_turn});
        }
    } else { 
        // Ancestor moved from h_prev to shadow, Spirit was stationary.
        for (int h_prev : REALM_GLOBAL[shadow]) {
            // Shadow Beast cannot enter the Sacred Portal (node 0)
            if (h_prev > 0) {
                res.push_back({spirit, h_prev, prev_turn});
            }
        }
    }
    return res;
}

/**
 * @brief Solves the game for a given graph using Retrograde BFS.
 * @return 1 (Spirit wins), 2 (Shadow wins), or 0 (Draw).
 */
int solve_for_output() {
    // Reset data structures
    outcome.assign(N_GLOBAL, vector<vector<int>>(N_GLOBAL, vector<int>(3, DRAW)));
    options.assign(N_GLOBAL, vector<vector<int>>(N_GLOBAL, vector<int>(3, 0)));
    q = queue<array<int, 4>>(); 

    // 1. Pre-calculate legal moves
    for (int s = 0; s < N_GLOBAL; ++s) {
        for (int h = 0; h < N_GLOBAL; ++h) {
            options[s][h][SPIRIT] = REALM_GLOBAL[s].size();
            options[s][h][SHADOW] = REALM_GLOBAL[h].size();
            
            for (int neighbor : REALM_GLOBAL[h]) {
                if (neighbor == 0) {
                    options[s][h][SHADOW]--; // Shadow cannot move to node 0
                    break;
                }
            }
        }
    }

    // 2. Initialize Base Cases (Terminal States)
    for (int i = 0; i < N_GLOBAL; ++i) {
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

    // 3. Retrograde BFS
    while (!q.empty()) {
        auto state = q.front(); q.pop();
        int s = state[0], h = state[1], turn_just_moved = state[2], winner_of_state = state[3];

        for (auto ancestor : get_ancestors(s, h, turn_just_moved)) {
            int s_prev = ancestor[0], h_prev = ancestor[1], t_prev = ancestor[2];
            
            if (outcome[s_prev][h_prev][t_prev] != DRAW) continue;
            
            // Case A: Current player (t_prev) moves to a guaranteed winning state.
            if (winner_of_state == t_prev) {
                outcome[s_prev][h_prev][t_prev] = winner_of_state;
                q.push({s_prev, h_prev, t_prev, winner_of_state});
            } else {
                // Case B: Current player (t_prev) moves to a guaranteed losing state (opponent wins).
                options[s_prev][h_prev][t_prev]--;
                
                // If all options lead to a loss, the opponent (3-t_prev) wins
                if (options[s_prev][h_prev][t_prev] == 0) {
                    int final_winner = 3 - t_prev; 
                    outcome[s_prev][h_prev][t_prev] = final_winner;
                    q.push({s_prev, h_prev, t_prev, final_winner});
                }
            }
        }
    }

    // 4. Final Result: Start state is (Spirit at 1, Shadow at 2, Spirit moves first (turn 1))
    return outcome[1][2][SPIRIT];
}

// -----------------------------------------------------------------------

void writeTest(int test_number) {
    // Setup input and output file streams
    std::stringstream input_ss;
    input_ss << "Input" << std::setfill('0') << std::setw(2) << test_number << ".txt";
    std::ofstream input_out(input_ss.str());

    std::stringstream output_ss;
    output_ss << "Output" << std::setfill('0') << std::setw(2) << test_number << ".txt";
    std::ofstream output_out(output_ss.str());

    // This problem requires T test cases in the input file format (t=1000 max)
    int t;
    if (test_number == 0) { // Small number of test cases
        t = rnd.next(5, 15);
    } else if (test_number == 1) { // Medium number of test cases
        t = rnd.next(100, 200);
    } else { // Max number of test cases
        t = 1000;
    }
    
    input_out << t << std::endl;

    // Constraints: 3 <= N <= 50
    const int MAX_N = 50;

    for (int i = 0; i < t; ++i) {
        // Graph size N
        if (test_number == 0) {
            N_GLOBAL = rnd.next(3, 10); 
        } else if (test_number == 1) {
            N_GLOBAL = rnd.next(11, 30); 
        } else { 
            N_GLOBAL = rnd.next(40, MAX_N); 
        }
        
        input_out << N_GLOBAL << std::endl;
        
        // Generate Adjacency List (Realm)
        REALM_GLOBAL.assign(N_GLOBAL, vector<int>());
        set<pair<int, int>> edges;
        
        int max_possible_edges = N_GLOBAL * (N_GLOBAL - 1) / 2;
        int target_edges;

        // Ensure a reasonable number of edges
        if (test_number == 2) {
            target_edges = rnd.next(max_possible_edges / 3, max_possible_edges); 
        } else {
            target_edges = rnd.next(N_GLOBAL - 1, max_possible_edges / 2);
        }
        
        // Generate random edges
        while (edges.size() < (size_t)target_edges) {
            int u = rnd.next(0, N_GLOBAL - 1);
            int v = rnd.next(0, N_GLOBAL - 1);
            
            if (u == v) continue; 
            if (u > v) swap(u, v); 
            
            edges.insert({u, v});
        }

        // Build the adjacency list
        for (const auto& edge : edges) {
            REALM_GLOBAL[edge.first].push_back(edge.second);
            REALM_GLOBAL[edge.second].push_back(edge.first);
        }
        
        // Sort the neighbors for canonical output, though not strictly required
        for (int j = 0; j < N_GLOBAL; ++j) {
            sort(REALM_GLOBAL[j].begin(), REALM_GLOBAL[j].end());
        }

        // Output the graph to the input file
        for (int j = 0; j < N_GLOBAL; ++j) {
            input_out << REALM_GLOBAL[j].size();
            for (int neighbor : REALM_GLOBAL[j]) {
                input_out << " " << neighbor;
            }
            input_out << std::endl;
        }
        
        // --- Calculate the solution and output ---
        
        int result = solve_for_output();
        output_out << result << std::endl;
    }

    input_out.close();
    output_out.close();
}


int main(int argc, char* argv[]) {
    // Replace the non-standard #include <bits/stdc++.h> with standard headers
    // and registers the generator.
    registerGen(argc, argv, 1);
    
    // Generate 3 sets of tests: small, medium, and large/max
    for (int no = 0; no < 3; no++) 
        writeTest(no);
        
    return 0;
}
