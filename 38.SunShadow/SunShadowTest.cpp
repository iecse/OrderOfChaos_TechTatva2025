#include "testlib.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <string>
#include <fstream>

// --- Solution Logic (Refactored) ---
bool is_palindrome(const std::vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    while (left < right) {
        if (arr[left] != arr[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

std::string computeAnswer(const std::vector<int>& spells) {
    std::vector<int> ley_line;
    for (int spell : spells) {
        if (spell > 0) {
            ley_line.push_back(spell);
        } else {
            // Negative spell, check for collisions
            while (!ley_line.empty() && ley_line.back() > 0 && spell < 0) {
                int sunfire = ley_line.back();
                if (sunfire > std::abs(spell)) {
                    ley_line.back() += spell; // Sunfire weakens
                    spell = 0; // Moonshadow is destroyed
                } else if (sunfire < std::abs(spell)) {
                    ley_line.pop_back(); // Sunfire is destroyed
                    spell += sunfire; // Moonshadow weakens
                } else {
                    ley_line.pop_back(); // Both are destroyed
                    spell = 0;
                }
            }
            if (spell != 0) {
                ley_line.push_back(spell);
            }
        }
    }

    if (is_palindrome(ley_line)) {
        return "Harmonious";
    } else {
        return "Chaotic";
    }
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
    const int MAX_TOTAL_N = 100000;
    const int MAX_POWER = 1000;

    for (int t = 0; t < T && total_n < MAX_TOTAL_N; ++t) {
        int n = rnd.next(1, std::min(1000, MAX_TOTAL_N - total_n));
        total_n += n;

        std::vector<int> spells(n);
        int test_type = rnd.next(1, 5);

        if (test_type == 1) { // Guaranteed Harmonious (post-collision)
            int half_len = n / 2;
            std::vector<int> half;
            for(int i=0; i < half_len; ++i) half.push_back(rnd.next(1, MAX_POWER));
            
            std::vector<int> reversed_half = half;
            std::reverse(reversed_half.begin(), reversed_half.end());
            
            spells.clear();
            spells.insert(spells.end(), half.begin(), half.end());
            if (n % 2 != 0) spells.push_back(rnd.next(1, MAX_POWER)); // Middle element
            spells.insert(spells.end(), reversed_half.begin(), reversed_half.end());
            // Sprinkle in some annihilating pairs
            int num_extra_pairs = rnd.next(1, 5);
            for(int i=0; i<num_extra_pairs && spells.size() < n; ++i) {
                int power = rnd.next(1, MAX_POWER);
                int pos = rnd.next(0, (int)spells.size());
                spells.insert(spells.begin() + pos, -power);
                spells.insert(spells.begin() + pos, power);
            }
            spells.resize(n); // Ensure size is exactly n
        } else if (test_type == 2) { // Guaranteed empty (Harmonious)
            int half_len = n / 2;
            spells.resize(n);
            for(int i = 0; i < half_len; ++i) spells[i] = rnd.next(1, MAX_POWER);
            for(int i = 0; i < half_len; ++i) spells[n-1-i] = -spells[i];
            if (n % 2 != 0) spells[half_len] = rnd.next(1,2) == 1 ? rnd.next(1,MAX_POWER) : rnd.next(-MAX_POWER,-1);
        } else if (test_type == 3) { // All positive or all negative (Harmonious if palindrome)
            bool all_pos = rnd.next(0,1);
            for(int i=0; i<n; ++i) {
                spells[i] = all_pos ? rnd.next(1, MAX_POWER) : rnd.next(-MAX_POWER, -1);
            }
        }
        else { // Random / likely Chaotic
            for (int i = 0; i < n; ++i) {
                spells[i] = rnd.next(1, 2) == 1 ? rnd.next(1, MAX_POWER) : rnd.next(-MAX_POWER, -1);
            }
        }

        fin << n << "\n";
        for (int i = 0; i < n; ++i) {
            fin << spells[i] << (i == n - 1 ? "" : " ");
        }
        fin << "\n";

        fout << computeAnswer(spells) << "\n";
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