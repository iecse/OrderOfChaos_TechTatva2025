#include <iostream>
#include <cmath>
using namespace std;

// Function to check if c can be written as a^2 + b^2
bool canStabilize(int c) {
    int spellA = 0;
    int spellB = static_cast<int>(sqrt(c));

    while (spellA <= spellB) {
        int totalPower = spellA * spellA + spellB * spellB;

        if (totalPower == c) {
            return true;
        } else if (totalPower < c) {
            spellA++;
        } else {
            spellB--;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int c;
        cin >> c;
        cout << (canStabilize(c) ? "true" : "false") << "\n";
    }

    return 0;
}
