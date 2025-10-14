#include <iostream>
#include <vector>
using namespace std;

// Determines if Eldoria can win the XOR game
bool canEldoriaWin(const vector<int>& arr) {
    int totalXor = 0;
    for (size_t i = 0; i < arr.size(); ++i) {
        totalXor ^= arr[i];
    }

    // Win immediately if total XOR sum is 0
    if (totalXor == 0) return true;

    // Otherwise, Eldoria can only win if number of elements is even
    return (arr.size() % 2 == 0);
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
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        cout << (canEldoriaWin(arr) ? "YES" : "NO") << "\n";
    }

    return 0;
}
