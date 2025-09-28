#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n;
    std::vector<long long> runes(n);
    long long total_sum = 0;
    std::unordered_map<long long, int> right_freq;

    // Read input, calculate total sum, and populate the frequency map for the right side
    for (int i = 0; i < n; ++i) {
        std::cin >> runes[i];
        total_sum += runes[i];
        right_freq[runes[i]]++;
    }

    // Case 1: No rune is removed.
    // We check if any prefix sum is exactly half of the total sum.
    long long prefix_sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        prefix_sum += runes[i];
        if (prefix_sum * 2 == total_sum) {
            std::cout << "YES\n";
            return;
        }
    }

    // Case 2: Exactly one rune is removed.
    // We iterate through all possible split points. At each point, we check if
    // removing a single rune from either the left or right group can balance the sums.
    prefix_sum = 0;
    std::unordered_map<long long, int> left_freq;
    for (int i = 0; i < n - 1; ++i) {
        // Update sums and frequencies for the current split point (after index i).
        // The element at index `i` moves from the right partition to the left.
        prefix_sum += runes[i];
        left_freq[runes[i]]++;
        
        right_freq[runes[i]]--;
        if (right_freq[runes[i]] == 0) {
            right_freq.erase(runes[i]);
        }
        
        long long left_sum = prefix_sum;
        long long right_sum = total_sum - prefix_sum;

        // Calculate the difference required to balance the sums
        long long diff = left_sum - right_sum;

        if (diff > 0) {
            // Left side is heavier. We need to remove a rune with value 'diff'
            // from the left partition to balance the sums.
            if (left_freq.count(diff)) {
                std::cout << "YES\n";
                return;
            }
        } else if (diff < 0) {
            // Right side is heavier. We need to remove a rune with value '-diff'
            // from the right partition to balance the sums.
            if (right_freq.count(-diff)) {
                std::cout << "YES\n";
                return;
            }
        }
        // If diff is 0, it's covered by Case 1.
    }

    // If no solution is found after checking all possibilities
    std::cout << "NO\n";
}

int main() {
    // Fast I/O for performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
