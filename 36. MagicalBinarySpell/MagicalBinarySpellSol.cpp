#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> subs;
        int count = 0, start = 0;

        // Decompose into special substrings
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') count++;
            else count--;

            if (count == 0) {
                // Recursive call for the inner substring
                string inner = s.substr(start + 1, i - start - 1);
                subs.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }

        // Sort in descending order to maximize lexicographical value
        sort(subs.begin(), subs.end(), greater<string>());

        // Concatenate all
        string result;
        for (auto &sub : subs) result += sub;
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    Solution sol;

    while (T--) {
        string s;
        cin >> s;
        cout << sol.makeLargestSpecial(s) << "\n";
    }
    return 0;
}
