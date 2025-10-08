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

// --- Correct Solution Function (ss/es version) ---
pair<int,int> wizardGuests(int n, int d, int k, const vector<pair<int,int>>& quests) {
    vector<int> ss(n + 1), es(n + 1);

    // Count starts and ends
    for (auto [a, b] : quests) {
        ss[a]++;
        es[b]++;
    }

    // Prefix sums
    for (int i = 0; i < n; i++) ss[i + 1] += ss[i];
    for (int i = 0; i < n; i++) es[i + 1] += es[i];

    int most = 0, least = 1e9;
    int brother = 0, mother = 0;

    // Check all possible d-day windows
    for (int i = d; i <= n; i++) {
        int cur = ss[i] - es[i - d];
        if (cur > most) {
            most = cur;
            brother = i - d + 1;
        }
        if (cur < least) {
            least = cur;
            mother = i - d + 1;
        }
    }

    return {brother, mother};
}

// --- Write one test file ---
void writeTest(int test_num) {
    string num = (test_num < 10 ? "0" : "") + to_string(test_num);
    ofstream fin("Input" + num + ".txt", ios::trunc);
    ofstream fout("Output" + num + ".txt", ios::trunc);

    int T = rnd.next(1, 1000); // constraint: 1 ≤ t ≤ 50
    fin << T << "\n";

    int totalN = 0;

    while (T--) {
        int n = rnd.next(1, 20000);  // keep n smaller so files are manageable
        int d = rnd.next(1, n);
        int k = rnd.next(1, min(n, 2000)); // avoid overly huge quest counts

        // Ensure sum(n) ≤ 2e5 across all scenarios
        if (totalN + n > 200000) {
            n = max(1, 200000 - totalN);
        }
        totalN += n;

        fin << n << " " << d << " " << k << "\n";

        vector<pair<int,int>> quests;
        for (int i = 0; i < k; i++) {
            int l = rnd.next(1, n);
            int r = rnd.next(l, n); // ensure l ≤ r
            quests.push_back({l, r});
            fin << l << " " << r << "\n";
        }

        auto [brother, mother] = wizardGuests(n, d, k, quests);
        fout << brother << " " << mother << "\n";
    }

    fin.close();
    fout.close();
}

// --- Main driver ---
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    for (int i = 0; i < 3; i++) {
        writeTest(i);
    }
    return 0;
}
