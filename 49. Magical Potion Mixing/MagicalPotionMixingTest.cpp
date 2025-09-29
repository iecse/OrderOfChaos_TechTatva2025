#include "../testlib.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// --- Solution Logic (same as problem) ---
int solve(vector<int>& gems) {
    int n = gems.size();
    int total = 0;  // now int is safe because constraints are reduced
    
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

    // Number of test cases (scaled down for file size, but ≤ 100000 in problem)
    int T = rnd.next(1, 50);  
    fin << T << "\n";

    while (T--) {
        int n = rnd.next(2, 200000);  // 2 ≤ n ≤ 2e5
        fin << n << "\n";

        vector<int> gems(n);
        for (int i = 0; i < n; i++) {
            gems[i] = rnd.next(1, 10000); // 1 ≤ gems[i] ≤ 10000
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
