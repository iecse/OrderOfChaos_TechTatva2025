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

// --- Solution function ---
double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    int n = quality.size();
    vector<pair<double, int>> ratio;
    ratio.reserve(n);

    for (int i = 0; i < n; i++) {
        ratio.push_back({(double)wage[i] / quality[i], quality[i]});
    }

    sort(ratio.begin(), ratio.end());

    priority_queue<int> maxHeap;
    long long sumQuality = 0;
    double res = 1e18;

    for (int i = 0; i < n; i++) {
        sumQuality += ratio[i].second;
        maxHeap.push(ratio[i].second);

        if ((int)maxHeap.size() > k) {
            sumQuality -= maxHeap.top();
            maxHeap.pop();
        }

        if ((int)maxHeap.size() == k) {
            res = min(res, ratio[i].first * sumQuality);
        }
    }

    return res;
}

// --- Write one test file ---
void writeTest(int test_num) {
    string num = (test_num < 10 ? "0" : "") + to_string(test_num);
    ofstream fin("Input" + num + ".txt");
    ofstream fout("Output" + num + ".txt");

    int T = rnd.next(1, 100);  // number of test cases
    fin << T << "\n";

    for (int tc = 0; tc < T; tc++) {
        int n = rnd.next(1, 10000);
        int k = rnd.next(1, n);

        vector<int> quality(n), wage(n);
        for (int i = 0; i < n; i++) quality[i] = rnd.next(1, 10000);
        for (int i = 0; i < n; i++) wage[i] = rnd.next(1, 10000);

        // Write input
        fin << n << " " << k << "\n";
        for (int i = 0; i < n; i++) fin << quality[i] << (i + 1 == n ? "\n" : " ");
        for (int i = 0; i < n; i++) fin << wage[i] << (i + 1 == n ? "\n" : " ");

        // Compute answer
        double ans = mincostToHireWorkers(quality, wage, k);
        fout << fixed << setprecision(5) << ans << "\n";
    }

    fin.close();
    fout.close();
}

// --- Main driver ---
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    for (int i = 0; i < 3; i++) {  // generate 3 test files
        writeTest(i);
    }
    return 0;
}
