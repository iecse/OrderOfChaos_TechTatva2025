#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

// Spell structure
struct Spell {
    int id;
    int deadline;
    int treasure;
};

// Solution function (same as in solution.cpp)
pair<vector<int>, int> enchantedQuest(vector<Spell>& spells, int n) {
    sort(spells.begin(), spells.end(), [](Spell a, Spell b){ return a.treasure > b.treasure; });

    int maxDeadline = 0;
    for (auto &s : spells) maxDeadline = max(maxDeadline, s.deadline);

    vector<int> slot(maxDeadline + 1, -1);
    vector<int> chosenSpells;
    int totalTreasure = 0;

    for (int i = 0; i < n; i++) {
        for (int t = spells[i].deadline; t > 0; t--) {
            if (slot[t] == -1) {
                slot[t] = spells[i].id;
                chosenSpells.push_back(spells[i].id);
                totalTreasure += spells[i].treasure;
                break;
            }
        }
    }

    return {chosenSpells, totalTreasure};
}

// Function to generate test files
void writeTest(int testNo) {
    string num = (testNo > 9) ? to_string(testNo) : "0" + to_string(testNo);
    fstream test("Input" + num + ".txt", ios::out);
    fstream answerFile("Output" + num + ".txt", ios::out);

    int remaining = 100000; // total sum of n across all tests
    int t = rnd.next(1, min(500, remaining));
    test << t << "\n";

    while (t-- && remaining > 0) {
        int n = rnd.next(1, min(100000, remaining));
        remaining -= n;
        test << n << "\n";

        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 1);

        // Fisher–Yates shuffle using rnd.next
        for (int i = n-1; i > 0; i--) {
            int j = rnd.next(0, i);
            swap(ids[i], ids[j]);
        }

        vector<Spell> spells(n);
        for (int i = 0; i < n; i++) {
            int id = ids[i];
            int deadline = rnd.next(1, n);
            int treasure = rnd.next(1, 10000);
            spells[i] = {id, deadline, treasure};
            test << id << " " << deadline << " " << treasure << "\n";
        }

        auto res = enchantedQuest(spells, n);
        for (int id : res.first) answerFile << id << " ";
        answerFile << "\n" << res.second << "\n";
    }

    test.close();
    answerFile.close();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    for (int no = 0; no < 3; no++) {
        writeTest(no); // creates Input00/Output00, Input01/Output01, Input02/Output02
    }

    return 0;
}
