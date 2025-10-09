#include <iostream>
using namespace std;

int minRituals(long long X) {
    int bits = 0;
    long long temp = X;
    while (temp > 0) {
        bits++;
        temp >>= 1; // divide by 2
    }
    return 2 * bits + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long X;
        cin >> X;
        cout << minRituals(X) << "\n";
    }
    return 0;
}
