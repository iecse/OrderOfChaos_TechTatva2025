#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

string answer(vector<int> runestones, int rune_power) {
    int n = runestones.size();
    bool lantern_used = false;
    int lantern_time = 0;
    bool escaped = true;

    for (int i = 0; i < n; i++) {
        if (runestones[i] == 0) {
            // shining stone
            if (lantern_time > 0) lantern_time--;
        } else {
            // shattered stone
            if (!lantern_used) {
                lantern_used = true;
                lantern_time = rune_power; // cover current + next (x-1)
                lantern_time--;            // consume for this step
            } else if (lantern_time > 0) {
                lantern_time--;
            } else {
                escaped = false;
                break;
            }
        }
    }

    return (escaped ? "YES" : "NO");
}

void writeTest(int testNo) {
    string num = (testNo > 9) ? to_string(testNo) : "0" + to_string(testNo);
    fstream test;
    fstream answerFile;
    test.open("Input" + num + ".txt", ios::out);
    answerFile.open("Output" + num + ".txt", ios::out);
    int n, x;
    vector<int> runestones;
    int t = rnd.next(1,1000);
    test << t << endl;

    while(t--) {
        n = rnd.next(1,1000);
        x = rnd.next(1, n);
        runestones.clear();
        for (int i = 0; i < n; i++) {
            runestones.push_back(rnd.next(0, 1));
        }
        test << n << " " << x << endl;
        for (int i = 0; i < n; i++) {
            test << runestones[i] << " ";
        }
        test << endl;
        answerFile << answer(runestones, x) << endl;
    }
    test.close();
    answerFile.close();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    for (int no = 0; no < 3; no++)
        writeTest(no);
    return 0;
}