#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath> // For std::min, std::max
// Note: Using standard includes instead of <bits/stdc++.h> for portability.

using namespace std;

// Solution function
int longestUniformAfterFlip(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return 1; // Can't improve a single element

    // 1. Compress the array into runs and values
    vector<int> runs;
    vector<int> values;
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && nums[j] == nums[i]) j++;
        runs.push_back(j - i);
        values.push_back(nums[i]);
        i = j;
    }

    int ans = 0;

    // Case A: Extend any existing run R_i by 1.
    // This is the minimum possible max length after a flip (unless n=0 or n=1).
    // It covers: max(initial_len) AND max(initial_len + 1)
    for (int len : runs) {
        ans = max(ans, len + 1);
    }

    // Case B: Merge two runs R_i and R_{i+2} separated by a single element (R_{i+1} of length 1)
    for (size_t i = 0; i + 2 < runs.size(); i++) {
        if (values[i] == values[i+2] && runs[i+1] == 1) {
            ans = max(ans, runs[i] + runs[i+2] + 1);
        }
    }

    // The result cannot exceed the total length of the array
    return min(ans, n);
}

// Main function for I/O (Kept as is for testing)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0; // Handle case where t might not be read

    while (t--) {
        int n;
        if (!(cin >> n)) break;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            if (!(cin >> nums[i])) return 0;
        }

        int result = longestUniformAfterFlip(nums);
        cout << result << "\n";
    }

    return 0;
}