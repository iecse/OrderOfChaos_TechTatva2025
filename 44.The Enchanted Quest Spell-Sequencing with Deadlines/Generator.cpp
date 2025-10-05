#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

struct Spell {
    int id, deadline, treasure;
};

// **FINAL CORRECT COMPARATOR**: Ensures generated output uses the same tie-breaker.
bool cmp(const Spell &a, const Spell &b) {
    if (a.treasure != b.treasure) {
        return a.treasure > b.treasure;
    }
    // Tie-breaker: Larger ID first
    return a.id > b.id; 
}

// DSU for scheduling
int findParent(vector<int> &parent, int s) {
    if (parent[s] == s) return s;
    return parent[s] = findParent(parent, parent[s]);
}

// Solution logic to compute sequence and treasure (used to generate output files)
pair<vector<int>, int> enchantedQuest(vector<Spell> &spells) {
    int maxDeadline = 0;
    for (auto &sp : spells) maxDeadline = max(maxDeadline, sp.deadline);

    // Use the deterministic sort
    sort(spells.begin(), spells.end(), cmp);

    vector<int> parent(maxDeadline + 1);
    for (int i = 0; i <= maxDeadline; i++) parent[i] = i;

    vector<int> result(maxDeadline + 1, -1);
    int totalTreasure = 0;

    for (auto &sp : spells) {
        int avail = findParent(parent, sp.deadline);
        if (avail > 0) {
            result[avail] = sp.id;
            totalTreasure += sp.treasure;
            parent[avail] = findParent(parent, avail - 1);
        }
    }

    vector<int> scheduled;
    for (int i = 1; i <= maxDeadline; i++) {
        if (result[i] != -1) scheduled.push_back(result[i]);
    }

    return {scheduled, totalTreasure};
}

// Function to generate test files
void writeTest(int testNo) {
    string num = (testNo > 9) ? to_string(testNo) : "0" + to_string(testNo);
    fstream test, answerFile;
    test.open("Input" + num + ".txt", ios::out);
    answerFile.open("Output" + num + ".txt", ios::out);

    int remaining = 100000; 
    int t = rnd.next(1, min(500, remaining));
    test << t << "\n";

    while (t-- && remaining > 0) {
        int n = rnd.next(1, min(100000, remaining));
        remaining -= n;

        test << n << "\n";
        vector<Spell> spells(n);
        for (int i = 0; i < n; i++) {
            spells[i].id = i + 1;
            spells[i].deadline = rnd.next(1, n);       
            spells[i].treasure = rnd.next(1, 10000);   
            test << spells[i].id << " " << spells[i].deadline 
                 << " " << spells[i].treasure << "\n";
        }

        auto res = enchantedQuest(spells);

        // Write scheduled spell IDs
        for (size_t i = 0; i < res.first.size(); i++) {
            answerFile << res.first[i] << (i == res.first.size() - 1 ? "" : " ");
        }
        answerFile << "\n";
        
        // Write total treasure
        answerFile << res.second << "\n";
    }
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    writeTest(0); 
    writeTest(1); 
    writeTest(2); 
    return 0;
}