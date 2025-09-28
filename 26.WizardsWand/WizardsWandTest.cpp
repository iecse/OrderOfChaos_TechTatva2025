#include "testlib.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
#include <fstream>

// Standard Kadane's algorithm from your solution
long long kadane(const std::vector<long long>& arr) {
    if (arr.empty()) {
        return 0; // Should not happen based on constraints
    }
    long long best_so_far = arr[0];
    long long current_max = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        current_max = std::max(arr[i], current_max + arr[i]);
        best_so_far = std::max(best_so_far, current_max);
    }
    return best_so_far;
}

// Refactored solution logic from your provided code
long long computeAnswer(const std::vector<long long>& a) {
    int n = a.size();
    if (n == 0) return 0;
    if (n == 1) {
        return a[0];
    }

    long long max_power = kadane(a);

    std::vector<long long> maxLeft(n);
    long long current_max = a[0];
    maxLeft[0] = a[0];
    for (int i = 1; i < n; ++i) {
        current_max = std::max(a[i], current_max + a[i]);
        maxLeft[i] = std::max(maxLeft[i - 1], current_max);
    }

    std::vector<long long> maxRight(n);
    current_max = a[n - 1];
    maxRight[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        current_max = std::max(a[i], current_max + a[i]);
        maxRight[i] = std::max(maxRight[i + 1], current_max);
    }

    for (int i = 0; i < n - 2; ++i) {
        max_power = std::max(max_power, maxLeft[i] + maxRight[i + 2]);
    }
    
    return max_power;
}

// Generates a single pair of test files
void writeTest(int test_num) {
    std::string num_str = (test_num < 10) ? "0" + std::to_string(test_num) : std::to_string(test_num);
    std::ofstream fin("Input" + num_str + ".txt");
    std::ofstream fout("Output" + num_str + ".txt");

    int T = rnd.next(50, 100);
    fin << T << "\n";

    int total_n = 0;
    const int MAX_TOTAL_N = 200000;
    const long long MAX_VAL = 1e9;

    for (int t = 0; t < T && total_n < MAX_TOTAL_N; ++t) {
        int n = rnd.next(1, std::min(2000, MAX_TOTAL_N - total_n));
        total_n += n;

        std::vector<long long> a(n);
        int test_type = rnd.next(1, 5);

        if (test_type == 1) { // Standard Kadane's is optimal
            for(int i = 0; i < n; ++i) a[i] = rnd.next(-MAX_VAL, -1LL);
            int start = rnd.next(0, n - 1);
            int end = rnd.next(start, n - 1);
            for(int i = start; i <= end; ++i) a[i] = rnd.next(1LL, MAX_VAL);
        } else if (test_type == 2) { // Reversal is optimal
            for(int i = 0; i < n; ++i) a[i] = rnd.next(-MAX_VAL, MAX_VAL);
            if (n >= 3) {
                int p1_end = rnd.next(0, n / 3);
                int p2_start = rnd.next(p1_end + 1, (2*n) / 3);
                for(int i = 0; i <= p1_end; ++i) a[i] = rnd.next(1LL, MAX_VAL / 1000);
                for(int i = p2_start; i < n; ++i) a[i] = rnd.next(1LL, MAX_VAL / 1000);
            }
        } else if (test_type == 3) { // All negative
            for(int i = 0; i < n; ++i) a[i] = rnd.next(-MAX_VAL, -1LL);
        } else { // Pure random
            for(int i = 0; i < n; ++i) a[i] = rnd.next(-MAX_VAL, MAX_VAL);
        }

        fin << n << "\n";
        for (int i = 0; i < n; ++i) {
            fin << a[i] << (i == n - 1 ? "" : " ");
        }
        fin << "\n";

        fout << computeAnswer(a) << "\n";
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