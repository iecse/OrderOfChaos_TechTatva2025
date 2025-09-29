#include <bits/stdc++.h>
using namespace std;

string decodeScroll(const string& s) {
    stack<int> numStack;
    stack<string> strStack;
    string currStr;
    int currNum = 0;

    for (char c : s) {
        if (isdigit(c)) {
            currNum = currNum * 10 + (c - '0');  // build number
        } else if (c == '[') {
            numStack.push(currNum);
            strStack.push(currStr);
            currNum = 0;
            currStr.clear();
        } else if (c == ']') {
            int repeat = numStack.top(); numStack.pop();
            string prevStr = strStack.top(); strStack.pop();
            string expanded;
            for (int j = 0; j < repeat; j++) {
                expanded += currStr;
            }
            currStr = prevStr + expanded;
        } else {
            currStr.push_back(c); // append character
        }
    }
    return currStr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cout << "Enter the magical scroll: ";
    cin >> s;

    string decoded = decodeScroll(s);
    cout << "Decoded spell: " << decoded << "\n";

    return 0;
}
