#include "../testlib.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// --- Solution Logic (same as problem) ---
int solve(vector<int>& gems) {
    int n = gems.size();
    int total = 0;
    
    for (int i = 0; i < n; i++) {
        total += gems[i];
        // Skip consecutive duplicates
        while (i + 1 < n && gems[i + 1] == gems[i]) {
            i++;
        }
    }
    return total;
}

// --- Write one test file ---
void writeTest(int z) {
    string num = (z < 10 ? "0" : "") + to_string(z);
    ofstream fin("Input" + num + ".txt", ios::trunc);
    ofstream fout("Output" + num + ".txt", ios::trunc);

    int T = rnd.next(1, 200);  // smaller: up to 10 test cases
    fin << T << "\n";

    while (T--) {
        int n = rnd.next(2, 50);  // smaller: 2 ≤ n ≤ 50
        fin << n << "\n";

        vector<int> gems(n);
        for (int i = 0; i < n; i++) {
            gems[i] = rnd.next(1, 100); // smaller: gem value 1 ≤ x ≤ 100
            fin << gems[i] << (i + 1 == n ? "\n" : " ");
        }

        fout << solve(gems) << "\n";
    }
}

// --- Main driver ---
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    for (int i = 0; i < 3; i++) { // generate 3 test files
        writeTest(i);
    }

    return 0;
}
