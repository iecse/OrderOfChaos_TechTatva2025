#include "testlib.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
#include <fstream>

std::vector<int> computeAnswer(std::vector<int> runes, long long k) {
    if (runes.empty()) {
        return {};
    }
    int n = runes.size();
    if (n > 0) {
        int effective_k = k % n;
        std::rotate(runes.begin(), runes.begin() + n - effective_k, runes.end());
    }
    return runes;
}

void writeTest(int test_num) {
    std::string num_str = (test_num < 10) ? "0" + std::to_string(test_num) : std::to_string(test_num);
    std::ofstream fin("Input" + num_str + ".txt");
    std::ofstream fout("Output" + num_str + ".txt");

    int T = rnd.next(5, 20);
    fin << T << "\n";

    int total_n = 0;
    const int MAX_TOTAL_N = 200;
    const int MAX_VAL = 100;

    for (int t = 0; t < T && total_n < MAX_TOTAL_N; ++t) {
        int n = rnd.next(1, std::min(20, MAX_TOTAL_N - total_n));
        total_n += n;
        
        long long k;
        int k_type = rnd.next(1, 5);
        if (k_type == 1) k = 0;
        else if (k_type == 2) k = n;
        else if (k_type == 3) {
            if (n > 1) {
                k = rnd.next(1, n - 1);
            } else {
                k = 1;
            }
        }
        else if (k_type == 4) k = rnd.next((long long)n + 1, 2LL * n);
        else k = rnd.next(0LL, 1000LL);
        
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
