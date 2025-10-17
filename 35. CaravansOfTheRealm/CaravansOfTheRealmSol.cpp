#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// Function to calculate number of wizard fleets
int carFleets(int target, const vector<int>& position, const vector<int>& speed) {
    int n = position.size();
    vector<double> times(n);

    for (int i = 0; i < n; i++) {
        times[i] = static_cast<double>(target - position[i]) / speed[i];
    }

    // Sort caravans by starting position (descending)
    vector<int> indices(n);
    for (int i = 0; i < n; i++) indices[i] = i;
    sort(indices.begin(), indices.end(),
         [&](int a, int b) { return position[a] > position[b]; });

    stack<double> st;
    for (int idx : indices) {
        double time = times[idx];
        if (st.empty() || time > st.top()) {
            st.push(time);
        }
    }

    return st.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, target;
        cin >> n >> target;

        vector<int> position(n), speed(n);
        for (int i = 0; i < n; i++) cin >> position[i];
        for (int i = 0; i < n; i++) cin >> speed[i];

        cout << carFleets(target, position, speed) << "\n";
    }

    return 0;
}
