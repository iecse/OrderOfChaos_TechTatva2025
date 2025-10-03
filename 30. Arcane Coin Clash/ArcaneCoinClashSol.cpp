#include <iostream>
#include <vector>
using namespace std;

long long solveScenario(int n, int k, const vector<int>& a, const vector<int>& b) {
    vector<pair<int, int>> vec;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int left = min(a[i], b[i]);
        int right = max(a[i], b[i]);
        ans += (right - left);
        vec.push_back({left, right});
    }

    sort(vec.begin(), vec.end());

    // Check for overlap
    for (int i = 1; i < n; i++) {
        if (vec[i].first <= vec[i - 1].second) {
            return ans;
        }
    }

    // No overlap: find minimum gap
    int mn = INT_MAX;
    for (int i = 1; i < n; i++) {
        mn = min(mn, vec[i].first - vec[i - 1].second);
    }

    return ans + 2LL * mn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        cout << solveScenario(n, k, a, b) << "\n";
    }
    return 0;
}
