#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(const string &s) {
    stack<int> counts;
    stack<string> resultStack;
    string current = "";
    int k = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            k = k * 10 + (ch - '0'); // build the repeat number
        } else if (ch == '[') {
            counts.push(k);
            resultStack.push(current);
            current = "";
            k = 0;
        } else if (ch == ']') {
            int repeat = counts.top(); counts.pop();
            string prev = resultStack.top(); resultStack.pop();
            string temp = "";
            for (int i = 0; i < repeat; i++) temp += current;
            current = prev + temp;
        } else {
            current += ch; // normal character
        }
    }

    return current;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore(); // ignore newline after t

    while (t--) {
        string s;
        getline(cin, s);
        cout << decodeString(s) << "\n";
    }

    return 0;
}
