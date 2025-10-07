#include "testlib.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <string>
#include <fstream>
#include <algorithm>

std::string computeAnswer(const std::vector<long long>& runes) {
    int n = runes.size();
    if (n < 2) return "NO";

    long long total_sum = 0;
    std::unordered_map<long long, int> right_freq;

    for (long long rune : runes) {
        total_sum += rune;
        right_freq[rune]++;
    }

    if (total_sum % 2 == 0) {
        long long half_sum = total_sum / 2;
        long long prefix_sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            prefix_sum += runes[i];
            if (prefix_sum == half_sum) {
                return "YES";
            }
        }
    }

    long long prefix_sum = 0;
    std::unordered_map<long long, int> left_freq;
    for (int i = 0; i < n - 1; ++i) {
        prefix_sum += runes[i];
        left_freq[runes[i]]++;
        
        right_freq[runes[i]]--;
        if (right_freq[runes[i]] == 0) {
            right_freq.erase(runes[i]);
        }
        
        long long left_sum = prefix_sum;
        long long right_sum = total_sum - prefix_sum;

        long long diff = left_sum - right_sum;

        if (diff > 0) {
            if (left_freq.count(diff)) {
                return "YES";
            }
        } else if (diff < 0) {
            if (right_freq.count(-diff)) {
                return "YES";
            }
        }
    }

    return "NO";
}

void writeTest(int test_num) {
    std::string num_str = (test_num < 10) ? "0" + std::to_string(test_num) : std::to_string(test_num);
    std::ofstream fin("Input" + num_str + ".txt");
    std::ofstream fout("Output" + num_str + ".txt");

    int T = 90;
    fin << T << "\n";

    int total_n = 0;
    const int MAX_TOTAL_N = 400000;
    const int MAX_RUNE = 10000;

    for (int t = 0; t < T && total_n < MAX_TOTAL_N; ++t) {
        int n = rnd.next(2, std::min(2000, MAX_TOTAL_N - total_n));
        total_n += n;

        std::vector<long long> runes(n);
        int test_type = rnd.next(1, 10);

        if (test_type <= 2) {
            long long left_sum = 0;
            int split_point = rnd.next(1, n - 1);
            for(int i = 0; i < split_point; ++i) {
                runes[i] = rnd.next(-MAX_RUNE, MAX_RUNE);
                left_sum += runes[i];
            }
            long long right_sum = 0;
            for(int i = split_point; i < n - 1; ++i) {
                runes[i] = rnd.next(-MAX_RUNE, MAX_RUNE);
                right_sum += runes[i];
            }
            runes[n - 1] = left_sum - right_sum;
            shuffle(runes.begin(), runes.end());
        } else if (test_type <= 4) {
            long long target_val = rnd.next(1, MAX_RUNE);
            runes[0] = target_val;
            long long sum = 0;
            for(int i = 1; i < n - 1; ++i) {
                runes[i] = rnd.next(-MAX_RUNE, MAX_RUNE);
                sum += runes[i];
            }
            runes[n-1] = sum;
            shuffle(runes.begin(), runes.end());
        } else if (test_type <= 6) {
            long long target_val = rnd.next(1, MAX_RUNE);
            runes[n-1] = target_val;
            long long sum = 0;
            for(int i = 1; i < n-1; ++i) {
                runes[i] = rnd.next(-MAX_RUNE, MAX_RUNE);
                sum += runes[i];
            }
            runes[0] = sum;
            shuffle(runes.begin(), runes.end());
        }
        else {
            for(int i = 0; i < n; ++i) {
                runes[i] = rnd.next(-MAX_RUNE, MAX_RUNE);
            }
        }

        fin << n << "\n";
        for (int i = 0; i < n; ++i) {
            fin << runes[i] << (i == n - 1 ? "" : " ");
        }
        fin << "\n";

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

