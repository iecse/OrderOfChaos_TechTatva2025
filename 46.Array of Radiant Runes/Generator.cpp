#include "../testlib.h"
#include <bits/stdc++.h>
#include <climits> // Include for LLONG_MIN
using namespace std;

// Solution logic to generate the output files
// **UPDATED to use long long**
vector<long long> radiantRunes(const vector<long long>& nums) {
    vector<long long> result; 
    long long maxRight = LLONG_MIN; // Use LLONG_MIN for safety
    int n = nums.size();

    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] > maxRight) { // strictly greater
            result.push_back(nums[i]);
            maxRight = nums[i];
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

void writeTest(int testNo) {
    string num = (testNo > 9) ? to_string(testNo) : "0" + to_string(testNo);
    fstream test, answerFile;
    test.open("Input" + num + ".txt", ios::out);
    answerFile.open("Output" + num + ".txt", ios::out);

    long long remaining = 100000; // sum of n across all test cases
    int t = rnd.next(1, min(500, (int)remaining));
    test << t << "\n";

    while (t-- && remaining > 0) {
        int n = rnd.next(1, min(100000, (int)remaining));
        remaining -= n;

        test << n << "\n";
        vector<long long> nums(n); // Use long long
        
        for (int i = 0; i < n; i++) {
            // Generate numbers in the range [-10^9, 10^9]
            nums[i] = rnd.next(-1000000000LL, 1000000000LL);
            test << nums[i] << (i + 1 == n ? "" : " ");
        }
        test << "\n";

        auto res = radiantRunes(nums);

        // Write radiant stars sequence
        for (size_t i = 0; i < res.size(); i++) {
            answerFile << res[i] << (i + 1 == res.size() ? "" : " ");
        }
        answerFile << "\n";
    }
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    writeTest(0); 
    writeTest(1); 
    writeTest(2); 
    return 0;
}