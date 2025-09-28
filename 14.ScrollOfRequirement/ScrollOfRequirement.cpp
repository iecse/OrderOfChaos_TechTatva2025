#include <iostream>
#include <string>
#include <unordered_map>
#include <limits>

// Function to solve a single test case
void solve() {
    std::string s, t;
    std::cin >> s >> t;

    if (t.length() > s.length()) {
        std::cout << "IMPOSSIBLE\n";
        return;
    }

    // Store the frequency of required runes from T
    std::unordered_map<char, int> need;
    for (char c : t) {
        need[c]++;
    }

    int left = 0;
    int have = 0;
    const int need_count = need.size(); // The number of unique runes we need
    
    // Variables to track the best window found
    int min_len = std::numeric_limits<int>::max();
    int start_index = -1;

    // A map to count runes in our current window
    std::unordered_map<char, int> window;

    // Expand the window by moving the 'right' pointer
    for (int right = 0; right < s.length(); ++right) {
        char c = s[right];
        window[c]++;
        
        // If 'c' is a required rune and we have now met its required count
        if (need.count(c) && window[c] == need[c]) {
            have++;
        }

        // Try to shrink the window from the left if it's currently valid
        while (have == need_count) {
            int current_len = right - left + 1;
            // If this window is the shortest so far, record it
            if (current_len < min_len) {
                min_len = current_len;
                start_index = left;
            }

            // Remove the leftmost character as we shrink the window
            char left_char = s[left];
            window[left_char]--;

            // If removing the left character makes the window invalid
            if (need.count(left_char) && window[left_char] < need[left_char]) {
                have--;
            }
            
            // Move the left pointer to shrink the window
            left++;
        }
    }
    
    // Output the result
    if (start_index == -1) {
        std::cout << "IMPOSSIBLE\n";
    } else {
        std::cout << s.substr(start_index, min_len) << "\n";
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int num_test_cases;
    std::cin >> num_test_cases;
    while (num_test_cases--) {
        solve();
    }
    return 0;
}