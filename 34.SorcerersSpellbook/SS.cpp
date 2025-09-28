#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Function to solve a single test case
void solve() {
    std::string s;
    std::cin >> s;

    // We can use a string as a stack to build the result
    std::string result = "";

    // Iterate through each rune of the input scroll
    for (char rune : s) {
        // Check for annihilation: if the result is not empty and the last rune
        // in the result is the same as the current rune, they annihilate.
        if (!result.empty() && result.back() == rune) {
            result.pop_back(); // Remove the last rune from the result
        } else {
            // Otherwise, the current rune is added to the scroll
            result.push_back(rune);
        }
    }

    // After all annihilations, check the final state of the scroll
    if (result.empty()) {
        std::cout << "Empty Spellbook\n";
    } else {
        std::cout << result << "\n";
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    // Read the number of test cases. Note: The problem description implies
    // multiple test cases, but the sample inputs only show one. This code
    // handles both scenarios correctly.
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
