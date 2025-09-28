#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Function to solve a single test case
void solve() {
    int n;
    long long H;
    std::cin >> n >> H;
    std::vector<int> caches(n);
    long long max_cache = 0;

    // Read cache values and find the maximum one, which sets the upper bound for our binary search.
    for (int i = 0; i < n; ++i) {
        std::cin >> caches[i];
        if (caches[i] > max_cache) {
            max_cache = caches[i];
        }
    }

    // Binary search for the minimum possible attunement factor 'k'.
    long long left = 1;
    long long right = max_cache;
    long long min_k = right; // Initialize with the worst-case answer

    while (left <= right) {
        long long k = left + (right - left) / 2;
        
        // Safety check for k=0, though it won't be reached with left initialized to 1.
        if (k == 0) { 
            left = 1;
            continue;
        }

        // Calculate the total cycles required for the current 'k'.
        long long total_cycles = 0;
        for (int cache_size : caches) {
            // This is an integer-safe way to compute ceil(cache_size / k).
            total_cycles += (long long)(cache_size + k - 1) / k;
        }

        if (total_cycles <= H) {
            // If we can finish in time, this 'k' is a potential answer.
            // Try for an even smaller 'k' to find the minimum.
            min_k = k;
            right = k - 1;
        } else {
            // If we need more time, 'k' is too small. We must increase it.
            left = k + 1;
        }
    }
    std::cout << min_k << std::endl;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read number of test cases
    while (t--) {
        solve();
    }
    return 0;
}