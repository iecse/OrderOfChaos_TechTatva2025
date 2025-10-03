#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


void solve() {
    // Fast I/O (optional, but good practice in competitive programming)
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    // Read the number of magic rods
    if (!(std::cin >> N)) return;

    // A map to store the frequency of each rod length.
    // Key: rod length (l_i), Value: count/frequency of that length.
    std::map<int, int> length_counts;

    int max_height = 0; // Stores the maximum frequency (height of the tallest tower)
    
    // Read the N rod lengths
    for (int i = 0; i < N; ++i) {
        int length;
        if (!(std::cin >> length)) break;

        // Increment the count for the current length
        length_counts[length]++;
        
        // Update the maximum height found so far
        // The current count for this length is the height of the tower it belongs to.
        max_height = std::max(max_height, length_counts[length]);
    }

    // The total number of towers is the number of distinct rod lengths.
    // In the map, this is simply the number of key-value pairs (the size of the map).
    int total_towers = length_counts.size();

    // Output the results in the required format:
    // 1. Height of the tallest Mystic Tower (max_height)
    // 2. Total number of towers (total_towers)
    std::cout << max_height << " " << total_towers << "\n";
}

int main() {
    solve();
    return 0;
}