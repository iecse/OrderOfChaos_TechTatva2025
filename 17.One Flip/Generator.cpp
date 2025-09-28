#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

// Solution function (same as in solution.cpp)
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
    for (int len : runs) ans = max(ans, len);

    for (int i = 0; i + 2 < runs.size(); i++) {
        if (values[i] == values[i+2] && runs[i+1] == 1) {
            ans = max(ans, runs[i] + runs[i+2] + 1);
        }
    }

    for (int len : runs) ans = max(ans, len + 1);
    return min(ans, n);
}

// Function to generate test files
void writeTest(int testNo) {
    string num = (testNo > 9) ? to_string(testNo) : "0" + to_string(testNo);
    fstream test, answerFile;

    test.open("Input" + num + ".txt", ios::out);
    answerFile.open("Output" + num + ".txt", ios::out);

    int remaining = 100000; // sum of n across all trials
    int t = rnd.next(1, min(10000, remaining));
    test << t << "\n";

    while (t-- && remaining > 0) {
        int n = rnd.next(1, max(1, min(100000, remaining)));
        remaining -= n;

        test << n << "\n";
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = rnd.next(0, 1);
            test << nums[i] << " ";
        }
        test << "\n";

        int res = longestUniformAfterFlip(nums);
        answerFile << res << "\n";
    }

    test.close();
    answerFile.close();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    for (int no = 0; no < 3; no++) {
        writeTest(no); // creates Input00/Output00, Input01/Output01, Input02/Output02
    }

    return 0;
}

