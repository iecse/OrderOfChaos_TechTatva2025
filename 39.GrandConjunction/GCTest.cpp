#include "testlib.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
#include <fstream>

// --- Solution Logic (Refactored & Optimized) ---
// We use an efficient vector-based rotation which produces the same
// result as the linked-list method but is much faster for a generator.
std::vector<int> computeAnswer(std::vector<int> runes, long long k) {
    if (runes.empty()) {
        return {};
    }
    int n = runes.size();
    if (n > 0) {
        int effective_k = k % n;
        // std::rotate brings the element at the middle iterator to the front.
        // For a right rotation by k, we want the element at n-k to be the new front.
        std::rotate(runes.begin(), runes.begin() + n - effective_k, runes.end());
    }
    return runes;
}
// --- End Solution Logic ---

// Generates a single pair of test files
void writeTest(int test_num) {
    std::string num_str = (test_num < 10) ? "0" + std::to_string(test_num) : std::to_string(test_num);
    std::ofstream fin("Input" + num_str + ".txt");
    std::ofstream fout("Output" + num_str + ".txt");

    int T = rnd.next(100, 200);
    fin << T << "\n";

    int total_n = 0;
    const int MAX_TOTAL_N = 200000;
    const int MAX_VAL = 10000;

    for (int t = 0; t < T && total_n < MAX_TOTAL_N; ++t) {
        int n = rnd.next(1, std::min(2000, MAX_TOTAL_N - total_n));
        total_n += n;
        
        long long k;
        int k_type = rnd.next(1, 5);
        if (k_type == 1) k = 0; // No rotation
        else if (k_type == 2) k = n; // No rotation
        else if (k_type == 3) k = rnd.next(1, n - 1); // Small rotation
        else if (k_type == 4) k = rnd.next((long long)n + 1, 2LL * n); // Rotation > n
        else k = rnd.next(0LL, 1000000000LL); // Large random rotation
        
        std::vector<int> runes(n);
        for(int i = 0; i < n; ++i) {
            runes[i] = rnd.next(-MAX_VAL, MAX_VAL);
        }

        fin << n << " " << k << "\n";
        for (int i = 0; i < n; ++i) {
            fin << runes[i] << (i == n - 1 ? "" : " ");
        }
        fin << "\n";
        
        std::vector<int> result = computeAnswer(runes, k);
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
    
    for (int i = 0; i < 3; ++i) {
        writeTest(i);
    }
    
    return 0;
}