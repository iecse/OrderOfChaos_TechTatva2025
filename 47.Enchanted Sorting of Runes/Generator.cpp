#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

// Include solution function
vector<int> magicalSorting(const vector<int>& nums) {
    vector<int> evens, odds;

    for (int x : nums) {
        if (x % 2 == 0) evens.push_back(x);
        else odds.push_back(x);
    }

    sort(evens.begin(), evens.end());
    sort(odds.begin(), odds.end(), greater<int>());

    vector<int> result;
    int ei = 0, oi = 0;
    for (int x : nums) {
        if (x % 2 == 0) result.push_back(evens[ei++]);
        else result.push_back(odds[oi++]);
    }

    return result;
}

// Function to generate test files
void writeTest(int testNo) {
    string num = (testNo > 9) ? to_string(testNo) : "0" + to_string(testNo);
    fstream test, answerFile;

    test.open("Input" + num + ".txt", ios::out);
    answerFile.open("Output" + num + ".txt", ios::out);

    int remaining = 100000; // sum of n across all test cases
    int t = rnd.next(1, min(500, remaining));
    test << t << "\n";

    while (t-- && remaining > 0) {
        int n = rnd.next(1, min(100000, remaining));
        remaining -= n;

        test << n << "\n";
        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            nums[i] = rnd.next(-1000000000, 1000000000); // -1e9 to 1e9
            test << nums[i] << " ";
        }
        test << "\n";

        vector<int> res = magicalSorting(nums);
        for (int x : res) answerFile << x << " ";
        answerFile << "\n";
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
