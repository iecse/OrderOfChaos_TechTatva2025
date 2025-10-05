#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // Include for LLONG_MIN

using namespace std;

/**
 * Solves the Array of Radiant Stars problem in O(N) time.
 * A star is radiant if it is strictly greater than all stars to its right.
 */
void solve() {
    int n;
    if (!(cin >> n)) return;
    
    // Use long long for array elements
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        if (!(cin >> nums[i])) return;
    }

    vector<long long> radiant_stars;
    
    // Initialize maxRight to the minimum possible long long value
    long long maxRight = LLONG_MIN; 

    // Iterate from right to left (The core O(N) algorithm)
    for (int i = n - 1; i >= 0; i--) {
        // If the current star is strictly greater than the maximum seen so far on its right
        if (nums[i] > maxRight) {
            radiant_stars.push_back(nums[i]);
            // Update the running maximum
            maxRight = nums[i]; 
        }
    }

    // Reverse the list to restore the original order
    reverse(radiant_stars.begin(), radiant_stars.end());

    // Output the result
    for (size_t i = 0; i < radiant_stars.size(); i++) {
        cout << radiant_stars[i] << (i + 1 == radiant_stars.size() ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Standard I/O optimization
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        solve();
    }

    return 0;
}