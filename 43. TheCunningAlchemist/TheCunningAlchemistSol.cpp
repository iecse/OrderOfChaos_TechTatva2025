#include <iostream>
#include <vector>
using namespace std;

long long solve(long long n) {
    // Precompute costs for each deal type
    vector<long long> cost;
    long long c = 3;
    long long cnt = 1;
    
    // Generate costs for deals (up to 21 iterations is sufficient for constraints)
    for (int i = 0; i < 21; i++) {
        cost.push_back(c);
        c = 3 * c + cnt;
        cnt *= 3;
    }
    
    long long minCost = 0;
    int sz = 0;
    
    // Convert n to base 3 and calculate minimum cost
    while (n > 0) {
        long long rem = n % 3;
        minCost += rem * cost[sz];
        n /= 3;
        sz++;
    }
    
    return minCost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n;
        cin >> n;
        cout << solve(n) << "\n";
    }
    
    return 0;
}