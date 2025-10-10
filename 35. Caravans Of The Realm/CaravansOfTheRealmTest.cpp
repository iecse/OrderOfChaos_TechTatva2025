#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>
#include "../testlib.h"
using namespace std;

int carFleets(int target, const vector<int>& position, const vector<int>& speed) {
    int n = position.size();
    vector<double> times(n);

    for (int i = 0; i < n; i++) {
        times[i] = static_cast<double>(target - position[i]) / speed[i];
    }

    // Sort caravans by starting position (descending)
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
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

void writeTest(int z) {
    string num = (z < 10 ? "0" : "") + to_string(z);
    ofstream test("Input" + num + ".txt", ios::trunc);
    ofstream answer("Output" + num + ".txt", ios::trunc);

    // Fixed: 100 test cases per file
    int T = 100;
    test << T << "\n";

    while (T--) {
        int n = rnd.next(1, 50);       // caravans
        int target = rnd.next(n + 1, 500); // ensure target > n

        test << n << " " << target << "\n";

        // Generate unique positions
        vector<int> allPos(target);
        iota(allPos.begin(), allPos.end(), 0);
        shuffle(allPos.begin(), allPos.end());

        vector<int> position(allPos.begin(), allPos.begin() + n);
        shuffle(position.begin(), position.end());

        for (int i = 0; i < n; i++) {
            test << position[i] << (i == n - 1 ? "\n" : " ");
        }

        // Speeds in [1, 50]
        vector<int> speed(n);
        for (int i = 0; i < n; i++) {
            speed[i] = rnd.next(1, 50);
            test << speed[i] << (i == n - 1 ? "\n" : " ");
        }

        int ans = carFleets(target, position, speed);
        answer << ans << "\n";
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    for (int no = 0; no < 3; no++) {
        writeTest(no);
    }
    return 0;
}
