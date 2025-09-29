#include <bits/stdc++.h>
using namespace std;

bool canEldoriaWin(const vector<int>& arr) {
    int totalXor = 0;
    for (int x : arr) totalXor ^= x;

    if (totalXor == 0) return true;           // Immediate win
    return (arr.size() % 2 == 0);             // Otherwise only win if n is even
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << (canEldoriaWin(arr) ? "YES\n" : "NO\n");
    }
    return 0;
}
