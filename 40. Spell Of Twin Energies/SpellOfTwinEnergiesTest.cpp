#include "../testlib.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

// Function to check if c can be written as a^2 + b^2
bool canStabilize(int c) {
    int spellA = 0;
    int spellB = static_cast<int>(sqrt(c));

    while (spellA <= spellB) {
        long long totalPower = 1LL * spellA * spellA + 1LL * spellB * spellB;

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

void writeTest(int z) {
    string num = (z > 9) ? to_string(z) : "0" + to_string(z);
    ofstream test("Input" + num + ".txt", ios::trunc);
    ofstream answer("Output" + num + ".txt", ios::trunc);

    // Number of test cases
    int T = rnd.next(1, 100000);  // constraint: 1 ≤ t ≤ 1e5
    test << T << "\n";

    while (T--) {
        int c = rnd.next(0, INT_MAX);  // 0 ≤ c ≤ 2^31 - 1
        test << c << "\n";
        answer << (canStabilize(c) ? "true" : "false") << "\n";
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    for (int no = 0; no < 3; no++) {  // generate 3 test files
        writeTest(no);
    }

    return 0;
}
