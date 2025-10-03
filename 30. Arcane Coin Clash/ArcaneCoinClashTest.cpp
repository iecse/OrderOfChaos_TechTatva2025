#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "../testlib.h"
using namespace std;

struct Interval {
    int l, r;
};

// --- Solution function (Arcane Coin Clash) ---
long long solveScenario(int n, int k, vector<int>& a, vector<int>& b) {
    vector<pair<int, int>> vec;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int x = a[i], y = b[i];
        if (y < x) swap(x, y);
        ans += (y - x);
        vec.push_back({x, y});
    }

    sort(vec.begin(), vec.end());

    // If any overlap exists, return ans
    for (int i = 1; i < n; i++) {
        if (vec[i].first <= vec[i - 1].second) {
            return ans;
        }
    }

    // Otherwise, add twice the minimum gap
    int mn = INT_MAX;
    for (int i = 1; i < n; i++) {
        mn = min(mn, vec[i].first - vec[i - 1].second);
    }

    return ans + 2LL * mn;
}

// --- Generate one test file ---
void writeTest(int test_num) {
    string num = (test_num < 10 ? "0" : "") + to_string(test_num);
    ofstream fin("Input" + num + ".txt");
    ofstream fout("Output" + num + ".txt");

    int T = rnd.next(1, 1000);  // number of test cases
    fin << T << "\n";

    int totalN = 0;

    while (T-- > 0) {
        // pick n, making sure totalN stays ≤ 2e5
        int remaining = 200000 - totalN;
        if (remaining <= 0) break;
        int n = rnd.next(1, min(2000, remaining)); // keep n varied, cap for balance
        totalN += n;

        int k = rnd.next(1, n);

        fin << n << " " << k << "\n";

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) a[i] = rnd.next(1, 1000000000);
        for (int i = 0; i < n; i++) b[i] = rnd.next(1, 1000000000);

        for (int i = 0; i < n; i++) {
            fin << a[i] << (i + 1 == n ? "\n" : " ");
        }
        for (int i = 0; i < n; i++) {
            fin << b[i] << (i + 1 == n ? "\n" : " ");
        }

        long long res = solveScenario(n, k, a, b);
        fout << res << "\n";
    }

    fin.close();
    fout.close();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    for (int i = 0; i < 3; i++) {  // generate 3 test files
        writeTest(i);
    }
    return 0;
}
