<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <numeric> // Only needed for more complex operations, but good practice
#include <algorithm>
#include <cmath>   // Not strictly needed here, but kept for context

using namespace std;

/**
 * @brief Determines the winner of the XOR game.
 * * NOTE: The winning conditions here are highly specific and depend entirely 
 * on the unstated rules of the game being played. This implementation assumes 
 * the following rules are mathematically correct for optimal play:
 * 1. Win if the total XOR sum is 0.
 * 2. Otherwise, win if the number of elements (N) is even.
 */
bool canEldoriaWin(const vector<int>& arr) {
    int totalXor = 0;
    // Calculate the total XOR sum (Nim-sum) of the array
    for (int x : arr) {
        totalXor ^= x;
    }

    if (totalXor == 0) {
        return true;           // Case 1: Eldoria wins immediately.
    }
    
    // Case 2: Eldoria wins only if the array size is even.
    return (arr.size() % 2 == 0);             
}

int main() {
    // Fast I/O optimization
=======
#include <bits/stdc++.h>
using namespace std;

bool canEldoriaWin(const vector<int>& arr) {
    int totalXor = 0;
    for (int x : arr) totalXor ^= x;

    if (totalXor == 0) return true;           // Immediate win
    return (arr.size() % 2 == 0);             // Otherwise only win if n is even
}

int main() {
>>>>>>> cc4f792068bb6026adb91173f7a89889029649cd
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
<<<<<<< HEAD
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        if (!(cin >> n)) break;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            if (!(cin >> arr[i])) break;
        }
        
=======
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
>>>>>>> cc4f792068bb6026adb91173f7a89889029649cd
        cout << (canEldoriaWin(arr) ? "YES\n" : "NO\n");
    }
    return 0;
}
