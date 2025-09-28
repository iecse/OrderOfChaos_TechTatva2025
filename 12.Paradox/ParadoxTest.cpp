#include "../testlib.h"
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <fstream>
#include <algorithm>

// Solution logic from your provided code
std::vector<int> nextStrongerWaits(const std::vector<int>& readings) {
    int n = readings.size();
    std::vector<int> ans(n, 0);
    std::stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && readings[i] > readings[s.top()]) {
            int idx = s.top();
            s.pop();
            ans[idx] = i - idx;
        }
        s.push(i);
    }
    return ans;
}

// Generates a single pair of test files (e.g., Input00.txt, Output00.txt)
void writeTest(int test_num) {
    std::string num_str = (test_num < 10) ? "0" + std::to_string(test_num) : std::to_string(test_num);
    std::ofstream fin("Input" + num_str + ".txt");
    std::ofstream fout("Output" + num_str + ".txt");

    int T = rnd.next(100, 200); // Number of test cases in this file
    fin << T << "\n";

    int total_n = 0;
    const int MAX_TOTAL_N = 500000;

    for (int t = 0; t < T && total_n < MAX_TOTAL_N; ++t) {
        int n;
        if (MAX_TOTAL_N - total_n <= 1) {
            n = 1;
        } else {
            n = rnd.next(1, std::min(5000, MAX_TOTAL_N - total_n));
        }
        total_n += n;

        std::vector<int> readings(n);
        int test_type = rnd.next(1, 5);

        if (test_type == 1) {
            // Strictly increasing sequence
            for (int i = 0; i < n; ++i) {
                readings[i] = i + 1;
            }
        } else if (test_type == 2) {
            // Strictly decreasing sequence
            for (int i = 0; i < n; ++i) {
                readings[i] = n - i;
            }
        } else if (test_type == 3) {
            // All same values
            int val = rnd.next(1, 1000000);
            for (int i = 0; i < n; ++i) {
                readings[i] = val;
            }
        } else {
            // Random values
            for (int i = 0; i < n; ++i) {
                readings[i] = rnd.next(1, 1000000);
            }
        }

        // Write to input file
        fin << n << "\n";
        for (int i = 0; i < n; ++i) {
            fin << readings[i] << (i == n - 1 ? "" : " ");
        }
        fin << "\n";

        // Calculate and write to output file
        std::vector<int> result = nextStrongerWaits(readings);
        for (int i = 0; i < n; ++i) {
            fout << result[i] << (i == n - 1 ? "" : " ");
        }
        fout << "\n";
    }

    fin.close();
    fout.close();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    // Generate 3 pairs of test files
    for (int i = 0; i < 3; ++i) {
        writeTest(i);
    }
    
    return 0;
}