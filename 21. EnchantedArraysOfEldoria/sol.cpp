#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int mn = *min_element(a.begin(), a.end());
        int mx = *max_element(a.begin(), a.end());

        // If min + max is already even, no removals are needed
        if ((mn + mx) % 2 == 0) {
            cout << 0 << "\n";
        } else {
            // Otherwise, remove either the min or the max (1 operation)
            cout << 1 << "\n";
        }
    }
    return 0;
}
