#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// A standard implementation of Kadane's algorithm to find the
// maximum sum of a contiguous subarray.
long long kadane(const std::vector<long long>& arr) {
    if (arr.empty()) {
        return 0;
    }
    long long best_so_far = arr[0];
    long long current_max = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        current_max = std::max(arr[i], current_max + arr[i]);
        best_so_far = std::max(best_so_far, current_max);
    }
    return best_so_far;
}

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (n == 1) {
        std::cout << a[0] << "\n";
        return;
    }

    // Case 1: No reversal is performed. The answer is the maximum
    // subarray sum of the original array.
    long long max_power = kadane(a);

    // --- Logic for the reversal case ---
    // The following logic, while not obviously a reversal, finds the
    // optimal solution by precomputing optimal subarrays on prefixes and suffixes.

    // Step 1: Precompute max subarray sum in every prefix a[0...i]
    std::vector<long long> maxLeft(n);
    long long current_max = a[0];
    maxLeft[0] = a[0];
    for (int i = 1; i < n; ++i) {
        current_max = std::max(a[i], current_max + a[i]);
        maxLeft[i] = std::max(maxLeft[i - 1], current_max);
    }

    // Step 2: Precompute max subarray sum in every suffix a[i...n-1]
    std::vector<long long> maxRight(n);
    current_max = a[n - 1];
    maxRight[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        current_max = std::max(a[i], current_max + a[i]);
        maxRight[i] = std::max(maxRight[i + 1], current_max);
    }

    // Step 3: Check for an improved sum. This step calculates the max sum of two
    // disjoint subarrays separated by exactly one element. This structure is equivalent
    // to a certain class of reversals that can join previously separate optimal parts.
    for (int i = 0; i < n - 2; ++i) {
        max_power = std::max(max_power, maxLeft[i] + maxRight[i + 2]);
    }
    
    std::cout << max_power << "\n";
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
