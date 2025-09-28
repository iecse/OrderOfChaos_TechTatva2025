#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

// Forward declarations for our helper functions
bool can_forge(const std::vector<int>& crystals, long long K, int max_instability);
bool has_sufficient_sum(const std::vector<int>& crystals, int l, int r, long long K);

// Function to solve a single test case
void solve() {
    int n;
    long long K;
    std::cin >> n >> K;
    std::vector<int> crystals(n);
    int max_abs_diff = 0;

    if (n > 0) {
        std::cin >> crystals[0];
    }
    for (int i = 1; i < n; ++i) {
        std::cin >> crystals[i];
        max_abs_diff = std::max(max_abs_diff, std::abs(crystals[i] - crystals[i - 1]));
    }

    if (n == 0) {
        std::cout << -1 << "\n";
        return;
    }

    // Binary search for the minimum possible instability.
    // The answer must lie between 0 and the max adjacent difference in the array.
    int left = 0, right = max_abs_diff, ans = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        // Check if it's possible to forge a blade with instability <= mid
        if (can_forge(crystals, K, mid)) {
            ans = mid;          // This is a potential answer, try for a better (smaller) one.
            right = mid - 1;
        } else {
            left = mid + 1;     // 'mid' is too small, need to allow more instability.
        }
    }
    std::cout << ans << "\n";
}

// Checks if a blade can be forged given a maximum allowed instability 'd'.
bool can_forge(const std::vector<int>& crystals, long long K, int d) {
    int n = crystals.size();
    if (n == 0) return false;

    int i = 0;
    while (i < n) {
        // Find the end 'j' of a contiguous chunk where all adjacent differences are <= d
        int j = i + 1;
        while (j < n && std::abs(crystals[j] - crystals[j - 1]) <= d) {
            j++;
        }

        // Now, check if any subarray within this valid chunk [i, j-1] has a sum >= K
        if (has_sufficient_sum(crystals, i, j - 1, K)) {
            return true;
        }
        
        // Move to the start of the next potential chunk
        i = j;
    }

    return false;
}

// Checks if any contiguous subarray within the range [l, r] has a sum >= K.
// This uses a standard and correct O(N) sliding window approach.
bool has_sufficient_sum(const std::vector<int>& crystals, int l, int r, long long K) {
    if (l > r) return false;

    long long window_sum = 0;
    int window_start = l;
    for (int window_end = l; window_end <= r; ++window_end) {
        window_sum += crystals[window_end];
        // While the current window's sum is sufficient, we have found a valid
        // subarray. If it becomes too small after shrinking, the outer loop will expand it again.
        while (window_sum >= K) {
            return true; // Found a valid subarray
        }
    }
    return false;
}

// Main function to handle test cases
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}