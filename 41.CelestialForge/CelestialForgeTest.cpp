#include "testlib.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <string>
#include <fstream>

// --- Solution Logic (Refactored) ---
bool has_sufficient_sum(const std::vector<int>& crystals, int l, int r, long long K) {
    if (l > r) return false;
    long long window_sum = 0;
    for (int window_end = l; window_end <= r; ++window_end) {
        window_sum += crystals[window_end];
        if (window_sum < 0) window_sum = 0; // Kadane's-like logic for general case
        if (window_sum >= K) {
            return true;
        }
    }
    // Also check single elements
    for(int i = l; i <= r; ++i) {
        if(crystals[i] >= K) return true;
    }
    return false;
}

bool can_forge(const std::vector<int>& crystals, long long K, int d) {
    int n = crystals.size();
    if (n == 0) return false;
    int i = 0;
    while (i < n) {
        int j = i + 1;
        while (j < n && std::abs(crystals[j] - crystals[j - 1]) <= d) {
            j++;
        }
        if (has_sufficient_sum(crystals, i, j - 1, K)) {
            return true;
        }
        i = j;
    }
    return false;
}

int computeAnswer(int n, long long K, const std::vector<int>& crystals) {
    if (n == 0) return -1;
    
    int max_abs_diff = 0;
    for (int i = 1; i < n; ++i) {
        max_abs_diff = std::max(max_abs_diff, std::abs(crystals[i] - crystals[i - 1]));
    }

    int left = 0, right = max_abs_diff, ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (can_forge(crystals, K, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}
// --- End Solution Logic ---


// Generates a single pair of test files
void writeTest(int test_num) {
    std::string num_str = (test_num < 10) ? "0" + std::to_string(test_num) : std::to_string(test_num);
    std::ofstream fin("Input" + num_str + ".txt");
    std::ofstream fout("Output" + num_str + ".txt");

    int T = rnd.next(50, 100);
    fin << T << "\n";

    int total_n = 0;
    const int MAX_TOTAL_N = 100000;
    const int MAX_CRYSTAL_VAL = 1e9;
    const long long MAX_K = 1e14;

    for (int t = 0; t < T && total_n < MAX_TOTAL_N; ++t) {
        int n = rnd.next(1, std::min(2000, MAX_TOTAL_N - total_n));
        total_n += n;
        
        std::vector<int> crystals(n);
        long long K;
        
        int test_type = rnd.next(1, 4);

        if (test_type == 1) { // Guaranteed low instability solution
            int stable_len = rnd.next(n/2, n);
            long long stable_sum = 0;
            int start_val = rnd.next(1, MAX_CRYSTAL_VAL / 2);
            for(int i = 0; i < stable_len; ++i) {
                int val = start_val + rnd.next(-100, 100);
                crystals[i] = val > 0 ? val : 1;
                stable_sum += crystals[i];
            }
            for(int i = stable_len; i < n; ++i) {
                crystals[i] = rnd.next(1, MAX_CRYSTAL_VAL);
            }
            K = rnd.next(stable_sum / 2, stable_sum);
        } else if (test_type == 2) { // Impossible case
            long long total_sum = 0;
            for(int i = 0; i < n; ++i) {
                crystals[i] = rnd.next(1, 1000); // Small values
                total_sum += crystals[i];
            }
            K = total_sum + rnd.next(1LL, 1000LL);
        } else { // Random case
            for(int i = 0; i < n; ++i) {
                crystals[i] = rnd.next(1, MAX_CRYSTAL_VAL);
            }
            K = rnd.next(1LL, MAX_K);
        }
        
        fin << n << " " << K << "\n";
        for (int i = 0; i < n; ++i) {
            fin << crystals[i] << (i == n - 1 ? "" : " ");
        }
        fin << "\n";

        fout << computeAnswer(n, K, crystals) << "\n";
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