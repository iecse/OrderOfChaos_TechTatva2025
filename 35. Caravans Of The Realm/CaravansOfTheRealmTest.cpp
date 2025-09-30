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

void writeTest(int z) {
    string num = (z > 9) ? to_string(z) : "0" + to_string(z);
    ofstream test("Input" + num + ".txt", ios::trunc);
    ofstream answer("Output" + num + ".txt", ios::trunc);

    // Number of test cases
    int T = rnd.next(1, 100); // fix: constraint is up to 100
    test << T << "\n";

    while (T--) {
        int n = rnd.next(1, 100000);
        int target = rnd.next(1, 1000000);

        // ensure we can actually pick n unique positions
        if (n >= target) n = target - 1;

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

        // Generate speeds in [1, 1e6]
        vector<int> speed(n);
        for (int i = 0; i < n; i++) {
            speed[i] = rnd.next(1, 1000000);
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
