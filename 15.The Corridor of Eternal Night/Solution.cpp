#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int trials;
    cin >> trials;

    while (trials--) {
        int n, rune_power;
        cin >> n >> rune_power;

        vector<int> runestones(n);
        for (int i = 0; i < n; i++) cin >> runestones[i];

        bool lantern_used = false;
        int lantern_time = 0;
        bool escaped = true;

        for (int i = 0; i < n; i++) {
            if (runestones[i] == 0) {
                // Shining runestone, step safely
                if (lantern_time > 0) lantern_time--; 
            } else {
                // Shattered runestone
                if (!lantern_used) {
                    lantern_used = true;
                    lantern_time = rune_power - 1; 
                } else if (lantern_time > 0) {
                    lantern_time--; 
                } else {
                    escaped = false;
                    break;
                }
            }
        }

        cout << (escaped ? "YES\n" : "NO\n");
    }

    return 0;
}