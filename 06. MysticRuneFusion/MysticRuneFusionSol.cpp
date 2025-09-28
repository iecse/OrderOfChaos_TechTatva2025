#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int mysticRuneFusion(const vector<int>& runes) {
    int n = runes.size();
    int maxSum = INT_MIN;

    for (int start = 0; start < n; start++) {
        for (int end = start; end < n; end++) {
            vector<int> fused = runes;

            for (int i = start + 1; i <= end; i++) {
                if (fused[i] > fused[i - 1] && fused[i - 1] != 0) {
                    fused[i] += fused[i - 1];
                    fused[i - 1] = 0;
                }
            }

            int sum = 0;
            for (int i = start; i <= end; i++) {
                sum += fused[i];
            }

            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    return maxSum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> runes(n);
        for (int i = 0; i < n; i++) {
            cin >> runes[i];
        }
        cout << mysticRuneFusion(runes) << "\n";
    }

    return 0;
}
