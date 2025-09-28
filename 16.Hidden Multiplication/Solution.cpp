#include <bits/stdc++.h>
using namespace std;

vector<long long> solve(long long n) {
    vector<long long> answers;

    // check k from 1 to 18 (since 10^18 is max)
    for (int k = 1; k <= 18; k++) {
        long long denom = 1 + (long long)pow(10, k);
        if (denom > n) break; // no need to check further
        if (n % denom == 0) {
            answers.push_back(n / denom);
        }
    }

    return answers;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        vector<long long> answers = solve(n);

        if (answers.empty()) {
            cout << 0 << "\n";
        } else {
            cout << answers.size();
            for (auto x : answers) cout << " " << x;
            cout << "\n";
        }
    }

    return 0;
}
