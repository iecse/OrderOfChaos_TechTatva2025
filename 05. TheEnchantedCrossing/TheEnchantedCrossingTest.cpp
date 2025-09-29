#include "../testlib.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

// --- Solution Logic (for generating outputs) ---
int enchantedCrossing(vector<int> tiles, const vector<int>& travelers) {
    int n = tiles.size();
    int m = travelers.size();
    int crossed = 0;

    for (int j = 0; j < m; j++) {
        int w = travelers[j];
        for (int i = 0; i < n; i++) {
            if (tiles[i] >= w) {
                tiles[i] -= w;
                crossed++;
                break;
            }
        }
    }
    return crossed;
}

// --- Write one test file ---
void writeTest(int z) {
    string num = (z < 10 ? "0" : "") + to_string(z);
    ofstream fin("Input" + num + ".txt", ios::trunc);
    ofstream fout("Output" + num + ".txt", ios::trunc);

    // Number of test cases
    int t = rnd.next(1, 100);  // 1 ≤ t ≤ 100
    fin << t << "\n";

    while (t--) {
        int n = rnd.next(1, 20000); // 1 ≤ n ≤ 20000
        int m = rnd.next(1, 20000); // 1 ≤ m ≤ 20000
        fin << n << " " << m << "\n";

        vector<int> tiles(n), travelers(m);

        for (int i = 0; i < n; i++) {
            tiles[i] = rnd.next(1, 1000000); // capacity ≤ 1e6
            fin << tiles[i] << (i == n - 1 ? "\n" : " ");
        }

        for (int j = 0; j < m; j++) {
            travelers[j] = rnd.next(1, 1000000); // weight ≤ 1e6
            fin << travelers[j] << (j == m - 1 ? "\n" : " ");
        }

        int ans = enchantedCrossing(tiles, travelers);
        fout << ans << "\n";
    }

    fin.close();
    fout.close();
}

// --- Main driver ---
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    for (int no = 0; no < 3; no++) {
        writeTest(no);
    }
    return 0;
}
