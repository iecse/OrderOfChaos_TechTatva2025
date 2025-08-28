#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long C;
        cin >> n >> C;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        int ans = n; // worst case: all cost 1
        for (int i = 0; i < n; i++) {
            long long cur = a[i];
            int cost = n - i; // assume all later relics are costly
            for (int j = i + 1; j < n; j++) {
                while (cur < a[j] && cur < C) cur *= 2; // grow cur
                if (cur >= a[j]) cost--; // destroy for free
                else cur = a[j];
            }
            ans = min(ans, cost);
        }

        cout << ans << "\n";
    }
    return 0;
}
