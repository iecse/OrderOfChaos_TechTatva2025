#include <bits/stdc++.h>
using namespace std;

int longestUniformAfterFlip(vector<int>& nums) {
    int n = nums.size();

    // Store lengths of consecutive runs
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

    // Try merging runs separated by exactly 1 flip
    for (int i = 0; i + 2 < runs.size(); i++) {
        if (values[i] == values[i+2] && runs[i+1] == 1) {
            ans = max(ans, runs[i] + runs[i+2] + 1);
        }
    }

    // Adding +1 flip inside a run (as long as array not length 1)
    for (int len : runs) {
        ans = max(ans, len + 1);
    }

    return min(ans, n); // cannot exceed array length
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {
        {1,1,0,1},
        {0,1,1,0,0,1},
        {0,0,0}
    };

    for (auto &nums : tests) {
        cout << longestUniformAfterFlip(nums) << "\n";
    }

    return 0;
}