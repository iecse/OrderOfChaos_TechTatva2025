#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>& gems) {
    int n = gems.size();
    int total = 0;  // int is safe under new constraints
    
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
