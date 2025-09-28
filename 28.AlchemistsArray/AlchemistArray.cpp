#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> potions(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> potions[i];
    }

    if (n == 0) {
        std::cout << "0\n";
        return;
    }

    // counts: map from potion essence -> its frequency
    std::unordered_map<int, int> counts;
    // freqs: map from a frequency -> number of essences with that frequency
    std::unordered_map<int, int> freqs;
    
    int longest_mix = 0;

    // We iterate through the array, considering prefixes of increasing length
    for (int i = 0; i < n; ++i) {
        int potion = potions[i];
        
        // --- Update counts and frequencies ---
        
        // 1. Find the old count of the current potion
        int old_count = counts[potion]; // Defaults to 0 if not present
        
        // 2. If the potion was already present, decrement the count of its old frequency
        if (old_count > 0) {
            freqs[old_count]--;
            if (freqs[old_count] == 0) {
                freqs.erase(old_count);
            }
        }

        // 3. Increment the potion's count and find its new frequency
        int new_count = old_count + 1;
        counts[potion] = new_count;
        
        // 4. Increment the count for the new frequency
        freqs[new_count]++;
        
        // --- Check if the current prefix is balanced ---
        
        bool is_balanced = false;
        
        // Condition 1: All elements have the same frequency.
        // e.g., [1,1,2,2] -> freqs is {2: 2}
        // e.g., [1,2,3] -> freqs is {1: 3}
        if (freqs.size() == 1) {
            is_balanced = true;
        } 
        // Condition 2: There are exactly two different frequencies.
        // We must check if these two frequencies differ by 1.
        // e.g., [1,1,2,2,3] -> freqs is {2: 2, 1: 1} -> freqs are 2 and 1.
        else if (freqs.size() == 2) {
            auto it = freqs.begin();
            int freq1 = it->first;
            it++;
            int freq2 = it->first;
            if (std::abs(freq1 - freq2) == 1) {
                is_balanced = true;
            }
        }
        
        if (is_balanced) {
            // The current prefix is balanced, so we update our answer
            longest_mix = i + 1;
        }
    }

    std::cout << longest_mix << "\n";
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
