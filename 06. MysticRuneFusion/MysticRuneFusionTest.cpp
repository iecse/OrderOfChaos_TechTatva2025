#include "../testlib.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

// --- Solution Logic (your O(n^3) version for correctness) ---
int computeAnswer(const vector<int>& runes) {
    int n = runes.size();
    int maxSum = INT_MIN;

    for (int start = 0; start < n; start++) {
        for (int end = start; end < n; end++) {
            vector<int> fused = runes;

            for (int i = start + 1; i <= end; i++) {
                if (fused[i] > fused[i - 1] && fused[i - 1] != 0) {
                    fused[i] += fused[i - 1];
                    fused[i - 1] = 0;
                }
            }

            int sum = 0;
            for (int i = start; i <= end; i++) {
                sum += fused[i];
            }

            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    return maxSum;
}
// --- End Solution Logic ---

// --- Test Generator ---
void writeTest(int test_num) {
    string num_str = (test_num < 10) ? "0" + to_string(test_num) : to_string(test_num);
    ofstream fin("Input" + num_str + ".txt");
    ofstream fout("Output" + num_str + ".txt");

    int T = rnd.next(1, 50);  // 1 ≤ t ≤ 50
    fin << T << "\n";

    const int MAX_N = 100;     // n ≤ 100
    const int MAX_VAL = 10000; // −10^4 ≤ runes[i] ≤ 10^4

    for (int t = 0; t < T; ++t) {
        int n = rnd.next(2, MAX_N); // 2 ≤ n ≤ 100
        fin << n << "\n";

        vector<int> runes(n);
        int test_type = rnd.next(1, 4);

        if (test_type == 1) { // Increasing sequence
            int current = rnd.next(-MAX_VAL, 0);
            for (int i = 0; i < n; ++i) {
                runes[i] = current;
                current += rnd.next(1, 50);
                if (runes[i] > MAX_VAL) runes[i] = MAX_VAL;
            }
        } else if (test_type == 2) { // Decreasing sequence
            int current = rnd.next(0, MAX_VAL);
            for (int i = 0; i < n; ++i) {
                runes[i] = current;
                current -= rnd.next(1, 50);
                if (runes[i] < -MAX_VAL) runes[i] = -MAX_VAL;
            }
        } else { // Random sequence
            for (int i = 0; i < n; ++i) {
                runes[i] = rnd.next(-MAX_VAL, MAX_VAL);
            }
        }

        // Write input
        for (int i = 0; i < n; ++i) {
            fin << runes[i] << (i == n - 1 ? "" : " ");
        }
        fin << "\n";

        // Write output using solution
        fout << computeAnswer(runes) << "\n";
    }

    fin.close();
    fout.close();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    for (int i = 0; i < 3; ++i) {
        writeTest(i);
    }

    return 0;
}
