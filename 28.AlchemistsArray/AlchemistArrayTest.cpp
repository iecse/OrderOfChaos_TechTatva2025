#include "testlib.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <string>
#include <fstream>

// Refactored solution logic from your provided code
int computeAnswer(const std::vector<int>& potions) {
    int n = potions.size();
    if (n == 0) {
        return 0;
    }

    std::unordered_map<int, int> counts;
    std::unordered_map<int, int> freqs;
    
    int longest_mix = 0;

    for (int i = 0; i < n; ++i) {
        int potion = potions[i];
        
        int old_count = counts[potion];
        
        if (old_count > 0) {
            freqs[old_count]--;
            if (freqs[old_count] == 0) {
                freqs.erase(old_count);
            }
        }

        int new_count = old_count + 1;
        counts[potion] = new_count;
        freqs[new_count]++;
        
        bool is_balanced = false;
        
        // This logic is tricky. Let's find the min and max frequencies present.
        int min_freq = -1, max_freq = -1;
        for(auto const& [freq, num_items] : freqs) {
            if (min_freq == -1 || freq < min_freq) min_freq = freq;
            if (max_freq == -1 || freq > max_freq) max_freq = freq;
        }

        if (max_freq - min_freq <= 1) {
            is_balanced = true;
        }
        
        if (is_balanced) {
            longest_mix = i + 1;
        }
    }

    return longest_mix;
}


// Generates a single pair of test files
void writeTest(int test_num) {
    std::string num_str = (test_num < 10) ? "0" + std::to_string(test_num) : std::to_string(test_num);
    std::ofstream fin("Input" + num_str + ".txt");
    std::ofstream fout("Output" + num_str + ".txt");

    int T = rnd.next(100, 200);
    fin << T << "\n";

    int total_n = 0;
    const int MAX_TOTAL_N = 200000;
    const int MAX_VAL = 100000;

    for (int t = 0; t < T && total_n < MAX_TOTAL_N; ++t) {
        int n = rnd.next(1, std::min(2000, MAX_TOTAL_N - total_n));
        total_n += n;

        std::vector<int> potions;
        int test_type = rnd.next(1, 4);

        if (test_type == 1) { // Fully balanced array
            int k = rnd.next(1, 5); // frequency
            int num_types = rnd.next(1, 10);
            for(int i = 1; i <= num_types; ++i) {
                for(int j = 0; j < k; ++j) potions.push_back(i);
            }
            if (rnd.next(0,1) && k > 1) { // maybe add one more element
                 potions.push_back(rnd.next(1, num_types));
            }
            shuffle(potions.begin(), potions.end());

        } else if (test_type == 2) { // Balanced prefix, unbalanced suffix
            int prefix_len = rnd.next(n / 2, n -1);
            if (prefix_len == 0) prefix_len = 1;
            
            int k = rnd.next(1, 5);
            int num_types = rnd.next(1, 10);
            for(int i = 1; i <= num_types; ++i) {
                for(int j = 0; j < k; ++j) potions.push_back(i);
            }
            shuffle(potions.begin(), potions.end());
            potions.resize(prefix_len); // trim to prefix
            
            // Add suffix that breaks balance
            while(potions.size() < n) {
                potions.push_back(rnd.next(MAX_VAL / 2, MAX_VAL));
            }

        } else { // Random case
            for(int i = 0; i < n; ++i) {
                potions.push_back(rnd.next(1, 20));
            }
        }
        
        n = potions.size();
        fin << n << "\n";
        for (int i = 0; i < n; ++i) {
            fin << potions[i] << (i == n - 1 ? "" : " ");
        }
        fin << "\n";

        fout << computeAnswer(potions) << "\n";
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