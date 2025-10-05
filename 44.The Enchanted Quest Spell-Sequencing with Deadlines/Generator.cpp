#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

struct Spell {
    int id, deadline, treasure;
};

// --- Comparator identical to Solution.cpp ---
bool cmp(const Spell &a, const Spell &b) {
    if (a.treasure != b.treasure)
        return a.treasure > b.treasure;
    return a.id < b.id; // smaller ID first
}

// --- Iterative DSU helper ---
int findParent(vector<int> &parent, int s) {
    while (parent[s] != s) {
        parent[s] = parent[parent[s]];
        s = parent[s];
    }
    return s;
}

// --- Logic identical to HackerRank solution ---
pair<vector<int>, int> enchantedQuest(vector<Spell> &spells) {
    int maxDeadline = 0;
    for (auto &sp : spells) maxDeadline = max(maxDeadline, sp.deadline);

    sort(spells.begin(), spells.end(), cmp);
    int n = (int)spells.size();
    maxDeadline = min(maxDeadline, n);

    vector<int> parent(maxDeadline + 1);
    iota(parent.begin(), parent.end(), 0);
    vector<int> result(maxDeadline + 1, -1);

    int totalTreasure = 0;
    for (auto &sp : spells) {
        int avail = findParent(parent, min(sp.deadline, maxDeadline));
        if (avail > 0) {
            result[avail] = sp.id;
            totalTreasure += sp.treasure;
            parent[avail] = findParent(parent, avail - 1);
        }
    }

    vector<int> scheduled;
    for (int i = 1; i <= maxDeadline; i++)
        if (result[i] != -1) scheduled.push_back(result[i]);

    return {scheduled, totalTreasure};
}

// --- File writer ---
void writeTest(int testNo) {
    string num = (testNo > 9) ? to_string(testNo) : "0" + to_string(testNo);
    fstream test("Input" + num + ".txt", ios::out);
    fstream ans("Output" + num + ".txt", ios::out);

    int remaining = 100000;
    int t = rnd.next(1, min(20, remaining / 5000 + 1)); // fewer large tests
    test << t << "\n";

    while (t-- && remaining > 0) {
        int n = rnd.next(1, min(10000, remaining));
        remaining -= n;

        test << n << "\n";
        vector<Spell> spells(n);
        for (int i = 0; i < n; i++) {
            spells[i].id = i + 1;
            spells[i].deadline = rnd.next(1, n);
            spells[i].treasure = rnd.next(1, 10000);
            test << spells[i].id << " " << spells[i].deadline << " " 
                 << spells[i].treasure << "\n";
        }

        auto res = enchantedQuest(spells);

        for (size_t i = 0; i < res.first.size(); i++) {
            if (i) ans << " ";
            ans << res.first[i];
        }
        ans << "\n" << res.second << "\n";
    }
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    writeTest(0);
    writeTest(1);
    writeTest(2);
    return 0;
}
