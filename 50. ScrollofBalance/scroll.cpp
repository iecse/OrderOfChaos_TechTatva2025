
#include <iostream>  // For cin, cout
#include <vector>    // For std::vector
#include <algorithm> // For std::sort, std::min, std::max, std::swap
#include <climits>   // For INT_MAX

#include <bits/stdc++.h>

using namespace std;

struct Pair {
    int first, second;
};

bool cmpPair(const Pair& a, const Pair& b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    vector<Pair> vec(n);

    for (int i = 1; i <= n; i++) cin >> a[i];

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int b;
        cin >> b;
        if (b < a[i]) swap(a[i], b);
        ans += (long long)(b - a[i]);
        vec[i - 1] = {a[i], b};
    }

    sort(vec.begin(), vec.end(), cmpPair);

    for (int i = 1; i < n; i++) {
        if (vec[i].first <= vec[i - 1].second) {
            cout << ans << "\n";
            return;
        }
    }

    int mn = INT_MAX;
    for (int i = 1; i < n; i++) {
        int diff = vec[i].first - vec[i - 1].second;
        mn = min(mn, diff);
    }

    cout << ans + 2LL * mn << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) solve();

    return 0;
}
