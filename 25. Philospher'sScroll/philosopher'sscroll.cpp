#include <iostream>  // Required for cin, cout, ios::sync_with_stdio, cin.tie
#include <string>    // Required for std::string
#include <stack>     // Required for std::stack

using namespace std;

string decodeScroll(const string& s) {
    stack<int> numStack;
    stack<string> strStack;
    string currStr;
    int currNum = 0;

    for (char c : s) {
        if (isdigit(c)) {
            // Build the repetition number (k). Handles multi-digit numbers.
            currNum = currNum * 10 + (c - '0');
        } else if (c == '[') {
            // Start of a nested segment: Save context.
            
            // 1. Push the repetition count.
            numStack.push(currNum);
            
            // 2. Push the string built *before* this bracket.
            strStack.push(currStr);
            
            // 3. Reset for the inner segment.
            currNum = 0;
            currStr.clear();
        } else if (c == ']') {
            // End of a nested segment: Perform expansion.
            
            // 1. Retrieve the repeat count (k) and the preceding string.
            int repeat = numStack.top(); numStack.pop();
            string prevStr = strStack.top(); strStack.pop();
            
            // 2. Expand the current segment (currStr).
            string expanded;
            for (int j = 0; j < repeat; j++) {
                expanded += currStr;
            }
            
            // 3. Update currStr to be the previously saved string plus the expansion.
            currStr = prevStr + expanded;
            
        } else {
            // Append a literal character.
            currStr.push_back(c);
        }
    }
    // The final result is the string built in the outermost scope.
    return currStr;
}

int main() {
    // Optimize input/output operations
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cout << "Enter the magical scroll: ";
    cin >> s;

    string decoded = decodeScroll(s);
    cout << "Decoded spell: " << decoded << "\n";

    return 0;
}
