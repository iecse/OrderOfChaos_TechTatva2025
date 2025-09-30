#include "../testlib.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <climits>
using namespace std;

// Function to check if c can be written as a^2 + b^2
bool canStabilize(int c) {
    int spellA = 0;
    int spellB = static_cast<int>(sqrt(c));

    while (spellA <= spellB) {
        long long totalPower = 1LL * spellA * spellA + 1LL * spellB * spellB;

        if (totalPower == c) return true;
        else if (totalPower < c) spellA++;
        else spellB--;
    }
    return false;
}

void writeTest(int z) {
    string num = (z > 9) ? to_string(z) : "0" + to_string(z);
    ofstream test("Input" + num + ".txt", ios::trunc);
    ofstream answer("Output" + num + ".txt", ios::trunc);

    int T = rnd.next(1, 1000);  // keep ≤ 1000 to avoid TLE with brute-force contestants
    test << T << "\n";

    // Add some fixed edge cases
    vector<int> edgeCases = {0, 1, INT_MAX};
    for (int c : edgeCases) {
        test << c << "\n";
        answer << (canStabilize(c) ? "true" : "false") << "\n";
        T--;
        if (T == 0) break;
    }

    // Fill the rest randomly
    while (T-- > 0) {
        int c = rnd.next(0, INT_MAX);
        test << c << "\n";
        answer << (canStabilize(c) ? "true" : "false") << "\n";
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    for (int no = 0; no < 3; no++) {
        writeTest(no);
    }
    return 0;
}
