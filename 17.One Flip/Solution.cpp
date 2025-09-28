#include <bits/stdc++.h>
using namespace std;

// Solution function
int longestUniformAfterFlip(const vector<int>& nums) {
    int n = nums.size();
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

    // Maximum run without any flip
    for (int len : runs) ans = max(ans, len);

    // Merge runs separated by exactly 1 flip
    for (int i = 0; i + 2 < runs.size(); i++) {
        if (values[i] == values[i+2] && runs[i+1] == 1) {
            ans = max(ans, runs[i] + runs[i+2] + 1);
        }
    }

    // Flip inside a run
    for (int len : runs) ans = max(ans, len + 1);

    return min(ans, n);
}

// Main function for I/O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t; // number of trials

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        int result = longestUniformAfterFlip(nums);
        cout << result << "\n";
    }

    return 0;
}
