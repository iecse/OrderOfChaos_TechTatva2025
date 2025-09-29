#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

// Solve function for the problem
vector<long long> solve(long long n) {
    vector<long long> answers;
    long long p10 = 10; // 10^1

    for (int k = 1; k <= 18; k++) {
        long long denom = 1 + p10;
        if (denom > n) break;
        if (n % denom == 0) {
            answers.push_back(n / denom);
        }
        if (p10 > (long long)1e18 / 10) break; // avoid overflow
        p10 *= 10;
    }
    return answers;
}

void writeTest(int testNo) {
    string num = (testNo > 9) ? to_string(testNo) : "0" + to_string(testNo);
    fstream test, answerFile;

    test.open("Input" + num + ".txt", ios::out);
    answerFile.open("Output" + num + ".txt", ios::out);

    // number of test cases
    int t = rnd.next(1, 10000);  
    test << t << "\n";

    while (t--) {
        long long n;

        // half the time, generate "valid" n = x * (1 + 10^k)
        if (rnd.next(0, 1)) {
            long long x = rnd.next(1LL, (long long)1e12); // safe range
            int k = rnd.next(1, 18);
            long long denom = 1 + (long long)pow(10, k);
            if (x > (long long)1e18 / denom) x = 1; // prevent overflow
            n = x * denom;
            if (n < 11) n = 11;
        } else {
            // random n
            n = rnd.next(11LL, (long long)1e18);
        }

        test << n << "\n";

        // write correct output
        vector<long long> res = solve(n);
        if (res.empty()) {
            answerFile << 0 << "\n";
        } else {
            answerFile << res.size();
            for (auto x : res) answerFile << " " << x;
            answerFile << "\n";
        }
    }

    test.close();
    answerFile.close();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    for (int no = 0; no < 3; no++) {
        writeTest(no);
    }
    return 0;
}
