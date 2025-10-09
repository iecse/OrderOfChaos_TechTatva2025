#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

long long solve() {
    int n;
    long long C;
    std::cin >> n >> C;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    for (int k = n; k >= 0; --k) {
        if (k == 0) {
            return n;
        }

        bool possible_to_destroy_k_for_free = true;

        for (int i = 0; i < k; ++i) {
            long long multiplier = 1LL;
            for (int j = 0; j < k - 1 - i; ++j) {
                if (multiplier > C) {
                    multiplier = C + 1; // prevent overflow
                    break;
                }
                multiplier *= 2;
            }

            if (multiplier > C || a[i] > C / multiplier) {
                possible_to_destroy_k_for_free = false;
                break;
            }
        }

        if (possible_to_destroy_k_for_free) {
            return n - k;
        }
    }

    return n;
}

int main() {
    int t;
    std::cin >> t;  // Number of test cases
    for (int test = 0; test < t; ++test) {
        std::cout << solve() << std::endl;
    }
    return 0;
}
