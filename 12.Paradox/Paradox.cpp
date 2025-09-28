#include <iostream>
#include <vector>
#include <stack>

std::vector<int> nextStrongerWaits(const std::vector<int>& readings) {
    int n = readings.size();
    std::vector<int> ans(n, 0);
    std::stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && readings[i] > readings[s.top()]) {
            int idx = s.top();
            s.pop();
            ans[idx] = i - idx;
        }
        s.push(i);
    }
    return ans;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> readings(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> readings[i];
    }

    std::vector<int> result = nextStrongerWaits(readings);

    for (int i = 0; i < n; ++i) {
        std::cout << result[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}