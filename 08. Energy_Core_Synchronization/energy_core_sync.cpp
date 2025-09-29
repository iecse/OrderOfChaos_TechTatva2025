#include <iostream>
<<<<<<< HEAD
#include <algorithm>

using namespace std;

/**
 * @brief Solves the Energy Core Synchronization problem.
 * The core challenge is the Synchronization Seal: energy[i] >= floor(energy[j] / 2).
 * The optimal strategy builds X by powers of 2, minimizing actions required to satisfy 
 * the seal during the growth.
 * The minimum number of steps required is consistently calculated as: 
 * (2 * number of bits in X) + 1.
 */
void solve() {
    // Read the target energy X as a long long to handle the 10^9 constraint
    long long x;
    if (!(cin >> x)) return;

    // 1. Count the number of bits in X
    int bits = 0;
    long long temp = x;
    
    // This loop counts the total number of significant bits in X.
    while (temp > 0) {
        bits++;
        temp >>= 1; // Right shift is equivalent to integer division by 2
    }

    // 2. Apply the correct formula: (2 * bits) + 1
    // This formula accounts for the minimum steps needed to build up X while 
    // satisfying the synchronization seal at every intermediate step.
    cout << 2 * bits + 1 << "\n";
}

int main() {
    // Fast I/O is standard practice for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0; // Read the number of test cases

    // Process all test cases
    while (t--) {
        solve();
    }

=======
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
>>>>>>> cc4f792068bb6026adb91173f7a89889029649cd
    return 0;
}
