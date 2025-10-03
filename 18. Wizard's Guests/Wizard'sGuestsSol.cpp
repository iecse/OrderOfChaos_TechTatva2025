#include <iostream>
#include <vector>
using namespace std;

void work() {
    int n, d, k;
    cin >> n >> d >> k;

    vector<int> ss(n + 1), es(n + 1);

    // Count quests starting/ending at each day
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        ss[a]++;
        es[b]++;
    }

    // Prefix sums
    for (int i = 0; i < n; i++) ss[i + 1] += ss[i];
    for (int i = 0; i < n; i++) es[i + 1] += es[i];

    int most = 0, least = 1e9;
    int brother = 0, mother = 0;

    // Check each possible d-day window
    for (int i = d; i <= n; i++) {
        int cur = ss[i] - es[i - d];
        if (cur > most) {
            most = cur;
            brother = i - d + 1; // earliest index
        }
        if (cur < least) {
            least = cur;
            mother = i - d + 1;
        }
    }

    cout << brother << " " << mother << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        work();
    }
    return 0;
}

