#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;

        int bits = 0;
        long long temp = x;
        while (temp > 0) {
            bits++;
            temp >>= 1; // divide by 2
        }

        // answer is number of bits + 2
        cout << bits + 2 << "\n";
    }
    return 0;
}
