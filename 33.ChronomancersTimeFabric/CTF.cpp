#include <iostream>
#include <vector>
#include <queue>
#include <utility>

// Function to solve a single test case
void solve() {
    int R, C;
    std::cin >> R >> C;
    std::vector<std::vector<int>> grid(R, std::vector<int>(C));
    
    // The queue for our Multi-Source BFS, storing coordinates {row, col}
    std::queue<std::pair<int, int>> q;
    int stable_count = 0;

    // Initialize the grid, find initial corruption sources, and count stable nexuses
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            std::cin >> grid[r][c];
            if (grid[r][c] == 1) {
                // This is a source of corruption, add it to the queue
                q.push({r, c});
            } else if (grid[r][c] == 0) {
                // This is a stable nexus we need to corrupt
                stable_count++;
            }
        }
    }

    // If there were no stable nexuses to begin with, it takes 0 ticks.
    if (stable_count == 0) {
        std::cout << 0 << "\n";
        return;
    }

    int ticks = 0;
    // Directions for adjacent cells: right, left, down, up
    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};

    // Perform BFS as long as there are sources of corruption and stable nexuses left
    while (!q.empty() && stable_count > 0) {
        // Process all nodes at the current level (one tick)
        int level_size = q.size();
        for (int i = 0; i < level_size; ++i) {
            std::pair<int, int> current = q.front();
            q.pop();
            int r = current.first;
            int c = current.second;

            // Spread to the four adjacent neighbors
            for (int j = 0; j < 4; ++j) {
                int new_r = r + dr[j];
                int new_c = c + dc[j];

                // Check if the neighbor is within bounds and is a stable nexus
                if (new_r >= 0 && new_r < R && new_c >= 0 && new_c < C && grid[new_r][new_c] == 0) {
                    grid[new_r][new_c] = 1; // It becomes corrupted
                    q.push({new_r, new_c}); // Add it to the queue for the next tick
                    stable_count--;
                }
            }
        }
        // A full level of the BFS has been processed, representing one tick of time
        ticks++;
    }

    // After the BFS, check if all stable nexuses were corrupted
    if (stable_count == 0) {
        std::cout << ticks << "\n";
    } else {
        // If stable_count > 0, some were unreachable
        std::cout << -1 << "\n";
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}