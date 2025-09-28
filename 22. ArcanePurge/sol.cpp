#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int solve() {
    int n;
    long long C;
    std::cin >> n >> C;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    // Find the maximum number of relics 'k' that can be destroyed for free.
    // We iterate from k=n down to 0.
    for (int k = n; k >= 0; --k) {
        if (k == 0) {
            // If we can't destroy any for free, the cost is n.
            return n;
        }

        bool possible_to_destroy_k_for_free = true;
        // To check if 'k' relics can be destroyed for free, we must use the 'k' smallest relics.
        // To give them the best chance, we destroy the largest of them (a[k-1]) first (time 0)
        // and the smallest (a[0]) last (time k-1).
        for (int i = 0; i < k; ++i) {
            // The i-th smallest relic (a[i]) is destroyed at time k-1-i.
            // Its weight will be a[i] * 2^(k-1-i).
            // We must check if a[i] * 2^(k-1-i) <= C.
            
            // To avoid overflow, we rewrite the check as: a[i] <= C / 2^(k-1-i)
            long long multiplier = 1LL << (k - 1 - i);
            if (multiplier > C || a[i] > C / multiplier) {
                possible_to_destroy_k_for_free = false;
                break;
            }
        }

        if (possible_to_destroy_k_for_free) {
            // If we can destroy 'k' relics for free, the remaining 'n-k' will cost mana.
            // This is the first (and therefore largest) k that works, so it gives the minimum cost.
            return n - k;
        }
    }

    return n; // Should not be reached, but acts as a fallback.
}
