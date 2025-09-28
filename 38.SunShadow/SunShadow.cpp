#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

// Function to check if a vector of integers is a palindrome
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

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> spells(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> spells[i];
    }

    // This vector will hold the spells remaining on the ley line after collisions.
    // We can use it like a stack.
    std::vector<int> ley_line;

    for (int spell : spells) {
        // Sunfire spells (positive) are always added to the line.
        if (spell > 0) {
            ley_line.push_back(spell);
        } 
        // Moonshadow spells (negative) trigger collision checks.
        else {
            bool moonshadow_survives = true;
            // While the moonshadow spell can collide with a sunfire spell on the line...
            while (!ley_line.empty() && ley_line.back() > 0) {
                int sunfire = ley_line.back();

                if (sunfire > std::abs(spell)) {
                    // Sunfire is stronger. It weakens, and the moonshadow is destroyed.
                    ley_line.back() += spell; // e.g., 10 + (-8) = 2
                    moonshadow_survives = false;
                    break;
                } else if (sunfire < std::abs(spell)) {
                    // Moonshadow is stronger. Sunfire is destroyed, moonshadow weakens.
                    ley_line.pop_back();
                    spell += sunfire; // e.g., -8 + 6 = -2
                } else {
                    // They are of equal power and annihilate each other.
                    ley_line.pop_back();
                    moonshadow_survives = false;
                    break;
                }
            }

            // If the moonshadow spell survived all collisions, it's added to the line.
            if (moonshadow_survives) {
                ley_line.push_back(spell);
            }
        }
    }

    // After all spells are processed, check if the final ley line is a palindrome.
    if (is_palindrome(ley_line)) {
        std::cout << "Harmonious\n";
    } else {
        std::cout << "Chaotic\n";
    }
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
