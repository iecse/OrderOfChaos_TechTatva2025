#include "../testlib.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// --- Solution Logic (to generate correct outputs) ---
long long solve(vector<int>& gems) {
    int n = gems.size();
    long long total = 0;
    
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

    // Number of test cases
    int T = rnd.next(1, 1000);  // up to 20 cases per file
    fin << T << "\n";

    while (T--) {
        int n = rnd.next(2, 200000);  // 2 ≤ n ≤ 2e5
        fin << n << "\n";

        vector<int> gems(n);
        for (int i = 0; i < n; i++) {
            gems[i] = rnd.next(1, 1000000000); // 1 ≤ gems[i] ≤ 1e9
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
