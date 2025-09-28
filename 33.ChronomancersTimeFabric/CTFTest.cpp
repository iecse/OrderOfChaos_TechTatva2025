#include "testlib.h"
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <fstream>
#include <algorithm>

// --- Solution Logic (Refactored) ---
int computeAnswer(int R, int C, std::vector<std::vector<int>> grid) { // Pass by value to allow modification
    std::queue<std::pair<int, int>> q;
    int stable_count = 0;

    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (grid[r][c] == 1) {
                q.push({r, c});
            } else if (grid[r][c] == 0) {
                stable_count++;
            }
        }
    }

    if (stable_count == 0) {
        return 0;
    }

    int ticks = 0;
    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};

    while (!q.empty()) {
        int level_size = q.size();
        if (stable_count == 0) break;
        
        ticks++; // A new tick starts as we process the current level
        
        for (int i = 0; i < level_size; ++i) {
            std::pair<int, int> current = q.front();
            q.pop();
            int r = current.first;
            int c = current.second;

            for (int j = 0; j < 4; ++j) {
                int new_r = r + dr[j];
                int new_c = c + dc[j];

                if (new_r >= 0 && new_r < R && new_c >= 0 && new_c < C && grid[new_r][new_c] == 0) {
                    grid[new_r][new_c] = 1;
                    q.push({new_r, new_c});
                    stable_count--;
                }
            }
        }
    }

    return (stable_count == 0) ? ticks : -1;
}
// --- End Solution Logic ---

// Generates a single pair of test files
void writeTest(int test_num) {
    std::string num_str = (test_num < 10) ? "0" + std::to_string(test_num) : std::to_string(test_num);
    std::ofstream fin("Input" + num_str + ".txt");
    std::ofstream fout("Output" + num_str + ".txt");

    int T = rnd.next(50, 100);
    fin << T << "\n";

    int total_size = 0;
    const int MAX_TOTAL_SIZE = 250000;

    for (int t = 0; t < T && total_size < MAX_TOTAL_SIZE; ++t) {
        int R = rnd.next(1, 100);
        int C = rnd.next(1, 100);
        if (total_size + R * C > MAX_TOTAL_SIZE) {
            R = C = 1; // Ensure we don't exceed the total size limit
        }
        total_size += R * C;

        std::vector<std::vector<int>> grid(R, std::vector<int>(C));
        int test_type = rnd.next(1, 5);

        if (test_type == 1) { // Unsolvable case (isolated stable nexuses)
            for (int r = 0; r < R; ++r) {
                for (int c = 0; c < C; ++c) grid[r][c] = rnd.next(1, 2); // Fill with corrupted/voids
            }
            // Carve out a space for stable nexuses and wall it off
            int r1 = rnd.next(0, R-1), c1 = rnd.next(0, C-1);
            int r2 = rnd.next(r1, R-1), c2 = rnd.next(c1, C-1);
            for(int r = r1; r <= r2; ++r) {
                for(int c = c1; c <= c2; ++c) grid[r][c] = 0;
            }
            for(int r = r1-1; r <= r2+1; ++r) {
                if(r >= 0 && r < R) {
                    if(c1 > 0) grid[r][c1-1] = 2;
                    if(c2 < C-1) grid[r][c2+1] = 2;
                }
            }
        } else if (test_type == 2) { // No stable nexuses
            for (int r = 0; r < R; ++r) {
                for (int c = 0; c < C; ++c) grid[r][c] = rnd.next(1, 2);
            }
        } else { // General random case (likely solvable)
            for (int r = 0; r < R; ++r) {
                for (int c = 0; c < C; ++c) {
                    int p = rnd.next(1, 100);
                    if (p <= 60) grid[r][c] = 0; // 60% chance of stable
                    else if (p <= 80) grid[r][c] = 2; // 20% chance of void
                    else grid[r][c] = 1; // 20% chance of corrupted
                }
            }
            if (rnd.next(0,1)) grid[rnd.next(0,R-1)][rnd.next(0,C-1)] = 1; // Ensure at least one source
        }

        fin << R << " " << C << "\n";
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                fin << grid[r][c] << (c == C - 1 ? "" : " ");
            }
            fin << "\n";
        }

        fout << computeAnswer(R, C, grid) << "\n";
    }

    fin.close();
    fout.close();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    for (int i = 0; i < 3; ++i) {
        writeTest(i);
    }
    
    return 0;
}