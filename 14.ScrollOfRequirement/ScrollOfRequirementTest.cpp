#include "../testlib.h"
#include "testlib.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits>
#include <fstream>
#include <algorithm>

// Refactored solution logic from your provided code
std::string computeAnswer(const std::string& s, const std::string& t) {
    if (t.length() > s.length()) {
        return "IMPOSSIBLE";
    }

    std::unordered_map<char, int> need;
    for (char c : t) {
        need[c]++;
    }

    int left = 0;
    int have = 0;
    const int need_count = need.size();
    
    int min_len = std::numeric_limits<int>::max();
    int start_index = -1;

    std::unordered_map<char, int> window;

    for (int right = 0; right < s.length(); ++right) {
        char c = s[right];
        window[c]++;
        
        if (need.count(c) && window[c] == need[c]) {
            have++;
        }

        while (have == need_count) {
            int current_len = right - left + 1;
            if (current_len < min_len) {
                min_len = current_len;
                start_index = left;
            }

            char left_char = s[left];
            window[left_char]--;

            if (need.count(left_char) && window[left_char] < need[left_char]) {
                have--;
            }
            
            left++;
        }
    }
    
    if (start_index == -1) {
        return "IMPOSSIBLE";
    } else {
        return s.substr(start_index, min_len);
    }
}


// Generates a single pair of test files (e.g., Input00.txt, Output00.txt)
void writeTest(int test_num) {
    std::string num_str = (test_num < 10) ? "0" + std::to_string(test_num) : std::to_string(test_num);
    std::ofstream fin("Input" + num_str + ".txt");
    std::ofstream fout("Output" + num_str + ".txt");

    int T = rnd.next(50, 100);
    fin << T << "\n";

    int total_s_len = 0;
    int total_t_len = 0;
    const int MAX_TOTAL_S = 200000;
    const int MAX_TOTAL_T = 100000;
    
    std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    for (int t_case = 0; t_case < T; ++t_case) {
        std::string s, t_str;
        int s_len = rnd.next(1, std::min(2000, MAX_TOTAL_S - total_s_len));
        int t_len = rnd.next(1, std::min(s_len, MAX_TOTAL_T - total_t_len));
        
        total_s_len += s_len;
        total_t_len += t_len;

        int test_type = rnd.next(1, 5);

        if (test_type <= 2) { // Guaranteed solvable case
            t_str = rnd.next("[a-z]{%d}", t_len);
            std::string shuffled_t = t_str;
            shuffle(shuffled_t.begin(), shuffled_t.end());
            
            int prefix_len = rnd.next(0, s_len - t_len);
            int suffix_len = s_len - t_len - prefix_len;

            s = rnd.next("[a-zA-Z0-9]{%d}", prefix_len) + shuffled_t + rnd.next("[a-zA-Z0-9]{%d}", suffix_len);
        } else if (test_type == 3) { // Impossible case (missing character)
            s = rnd.next("[a-z]{%d}", s_len);
            t_str = rnd.next("[A-Z]{%d}", t_len);
        } else if (test_type == 4) { // Impossible case (insufficient frequency)
             s = rnd.next("[ab]{%d}", s_len);
             t_str = s + "a"; // Guarantee 'a' is needed more times than it appears in s
             if (t_str.length() > MAX_TOTAL_T - total_t_len + t_len) {
                 t_str = "aa"; // Fallback
             }
        } else { // Pure random
            s = rnd.next("[a-zA-Z]{%d}", s_len);
            t_str = rnd.next("[a-zA-Z]{%d}", t_len);
        }

        fin << s << "\n";
        fin << t_str << "\n";
        fout << computeAnswer(s, t_str) << "\n";
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