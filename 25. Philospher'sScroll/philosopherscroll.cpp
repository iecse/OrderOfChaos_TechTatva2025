#include <iostream>  // For cout, cin, ios::sync_with_stdio, cin.tie
#include <string>    // For std::string
#include <stack>     // For std::stack
#include <vector>    // Often useful, but implicitly included by stack/string headers on some systems. Best to keep standard headers explicit.

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
    // Note: cin >> s; will only read up to the first whitespace. 
    // If the scroll can contain spaces, you should use getline(cin, s);
    cin >> s; 

    string decoded = decodeScroll(s);
    cout << "Decoded spell: " << decoded << "\n";

    return 0;
}