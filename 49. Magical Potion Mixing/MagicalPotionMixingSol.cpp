#include <iostream>
#include <vector>
using namespace std;

// Using long long is NECESSARY to avoid overflow
// Worst case: 200,000 gems * 10^9 each = 2*10^14 (exceeds int limit)
long long solve(vector<int>& gems) {
    int n = gems.size();
    long long total = 0;
    
    for (int i = 0; i < n; i++) {
        total += gems[i];
        // Skip all consecutive duplicates
        while (i + 1 < n && gems[i + 1] == gems[i]) {
            i++;
        }
    }
    
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> gems(n);
        for (int i = 0; i < n; i++) {
            cin >> gems[i];
        }
        
        cout << solve(gems) << "\n";
    }
    
    return 0;
}