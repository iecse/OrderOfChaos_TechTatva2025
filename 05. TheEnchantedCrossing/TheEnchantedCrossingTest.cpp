#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "../testlib.h"
using namespace std;


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

void writeTest(int z) {
    string num = (z > 9) ? to_string(z) : "0" + to_string(z);
    fstream test;
    fstream answer;
    test.open("Input" + num + ".txt", ios::out);
    answer.open("Output" + num + ".txt", ios::out);

    // Number of test cases
    int t = rnd.next(1, 1000);
    test << t << "\n";

    while (t--) {
        int n = rnd.next(1, 100000);  // small range for manageable output
        int m = rnd.next(1, 100000);

        test << n << " " << m << "\n";

        vector<int> tiles(n), travelers(m);

        for (int i = 0; i < n; i++) {
            tiles[i] = rnd.next(1, 1000000000); // tile capacity
            test << tiles[i] << (i == n - 1 ? "\n" : " ");
        }

        for (int j = 0; j < m; j++) {
            travelers[j] = rnd.next(1, 1000000000); // traveler weight
            test << travelers[j] << (j == m - 1 ? "\n" : " ");
        }

        int ans = enchantedCrossing(tiles, travelers);
        answer << ans << "\n";
    }

    test.close();
    answer.close();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    for (int no = 0; no < 3; no++) {
        writeTest(no);
    }
    return 0;
}