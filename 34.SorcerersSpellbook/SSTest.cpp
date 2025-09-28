#include "testlib.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

// --- Solution Logic (Refactored) ---
std::string computeAnswer(const std::string& s) {
    std::string result = "";
    for (char rune : s) {
        if (!result.empty() && result.back() == rune) {
            result.pop_back();
        } else {
            result.push_back(rune);
        }
    }

    if (result.empty()) {
        return "Empty Spellbook";
    } else {
        return result;
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

    int total_s_len = 0;
    const int MAX_TOTAL_S = 200000;

    for (int t = 0; t < T && total_s_len < MAX_TOTAL_S; ++t) {
        int n = rnd.next(1, std::min(2000, MAX_TOTAL_S - total_s_len));
        total_s_len += n;

        std::string s;
        int test_type = rnd.next(1, 5);

        if (test_type == 1) { // Guaranteed empty result
            int half_len = n / 2;
            std::string half = rnd.next("[a-z]{%d}", half_len);
            std::string reversed_half = half;
            std::reverse(reversed_half.begin(), reversed_half.end());
            s = half + reversed_half;
            if (n % 2 != 0) { // If n is odd, add a random char in the middle
                s.insert(half_len, 1, rnd.next('a', 'z'));
            }
        } else if (test_type == 2) { // Chain reaction case
            s = rnd.next("[a-z]{%d}", n/4 + 1); // Start with a small final string
            while(s.length() < n) {
                char c = rnd.next('a', 'z');
                int pos = rnd.next(0, (int)s.length());
                std::string to_insert;
                to_insert += c;
                to_insert += c;
                s.insert(pos, to_insert);
                if (s.length() > n) {
                    s = s.substr(0, n);
                    break;
                }
            }
        } else if (test_type == 3) { // No annihilations
            s = "";
            for(int i=0; i<n; ++i) {
                char c;
                do {
                    c = rnd.next('a', 'z');
                } while (!s.empty() && s.back() == c);
                s += c;
            }
        }
        else { // Random case
            s = rnd.next("[a-z]{%d}", n);
        }

        fin << s << "\n";
        fout << computeAnswer(s) << "\n";
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