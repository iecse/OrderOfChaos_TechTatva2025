#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    int n = quality.size();
    vector<pair<double, int>> ratio; 
    ratio.reserve(n);

    for (int i = 0; i < n; i++) {
        ratio.push_back({(double)wage[i] / quality[i], quality[i]});
    }

    sort(ratio.begin(), ratio.end());

    priority_queue<int> maxHeap;
    long long sumQuality = 0;
    double res = 1e18;

    for (int i = 0; i < n; i++) {
        sumQuality += ratio[i].second;
        maxHeap.push(ratio[i].second);

        if ((int)maxHeap.size() > k) {
            sumQuality -= maxHeap.top();
            maxHeap.pop();
        }

        if ((int)maxHeap.size() == k) {
            res = min(res, ratio[i].first * sumQuality);
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    cout << fixed << setprecision(5);

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int> quality(n), wage(n);
        for (int i = 0; i < n; i++) cin >> quality[i];
        for (int i = 0; i < n; i++) cin >> wage[i];

        double ans = mincostToHireWorkers(quality, wage, k);
        cout << ans << "\n";
    }

    return 0;
}
