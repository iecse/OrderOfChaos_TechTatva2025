#include "../testlib.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> subs;
        int count = 0, start = 0;

        // Decompose into special substrings
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '1') count++;
            else count--;

            if (count == 0) {
                // Recursive call for inner substring
                string inner = s.substr(start + 1, i - start - 1);
                subs.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }

        // Sort in descending order
        sort(subs.begin(), subs.end(), greater<string>());

        // Concatenate
        string result;
        for (auto &sub : subs) result += sub;
        return result;
    }
};

// Generate a random balanced spell of length n
string genBalanced(int n) {
    if (n == 0) return "";
    if (n == 2) return "10"; // smallest valid

    // Pick a random split point (must be even)
    int k = rnd.next(2, n - 2);
    if (k % 2 == 1) k++;

    string left = genBalanced(k);
    string right = genBalanced(n - k);

    return "1" + left + "0" + right;
}

void writeTest(int z) {
    Solution sol;

    string num = (z < 10 ? "0" : "") + to_string(z);
    ofstream fin("Input" + num + ".txt", ios::trunc);
    ofstream fout("Output" + num + ".txt", ios::trunc);

    int T = rnd.next(1, 999);  // 1 ≤ T < 1000
    fin << T << "\n";

    while (T--) {
        int n = rnd.next(2, 50); // 2 ≤ n ≤ 50
        if (n % 2 == 1) n++;     // ensure even

        string s = genBalanced(n);
        fin << s << "\n";

        fout << sol.makeLargestSpecial(s) << "\n";
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    for (int no = 0; no < 3; no++) {
        writeTest(no);
    }
    return 0;
}
