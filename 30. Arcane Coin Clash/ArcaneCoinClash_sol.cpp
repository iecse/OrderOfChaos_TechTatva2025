#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5+5;

int n, k, a[MXN];

void Main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    vector<pair<int, int>> vec;
    long long ans = 0;
    for(int i=1, b; i<=n; i++) {
        cin >> b;
        if(b<a[i]) swap(b, a[i]);
        ans += b-a[i];
        vec.push_back({a[i], b});
    }
    sort(vec.begin(), vec.end());
    for(int i=1; i<n; i++)
        if(vec[i].first<=vec[i-1].second) {
            cout << ans << '\n';
            return;
        }
    int mn = 2e9;
    for(int i=1; i<n; i++)
        mn = min(mn, vec[i].first - vec[i-1].second);
    cout << ans + 2*mn << '\n';
}

int32_t main() {
    int tc;
    cin >> tc;
    while(tc--) Main();
}
