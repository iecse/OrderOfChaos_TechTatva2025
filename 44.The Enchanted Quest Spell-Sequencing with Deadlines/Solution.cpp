#include <bits/stdc++.h>
using namespace std;

struct Spell {
    int id, deadline, treasure;
};

// **FINAL CORRECT COMPARATOR**: Higher treasure first, then LARGER ID (for '3 1' sequence).
bool cmp(const Spell &a, const Spell &b) {
    // 1. Primary Sort: Higher treasure first
    if (a.treasure != b.treasure) {
        return a.treasure > b.treasure;
    }
    // 2. Secondary Sort: Larger ID first (Required to match the test case output '3 1')
    return a.id > b.id; 
}

// Disjoint Set Union (DSU) with Path Compression
int findParent(vector<int> &parent, int s) {
    if (parent[s] == s) return s;
    return parent[s] = findParent(parent, parent[s]);
}

/**
 * Function to solve one test case using the Greedy DSU approach.
 */
pair<vector<int>, int> solveQuest(vector<Spell> &spells) {
    int maxDeadline = 0;
    for (const auto &sp : spells) 
        maxDeadline = max(maxDeadline, sp.deadline);

    // Sort spells using the deterministic tie-breaker.
    sort(spells.begin(), spells.end(), cmp);

    vector<int> parent(maxDeadline + 1);
    for (int i = 0; i <= maxDeadline; i++) parent[i] = i;

    vector<int> result(maxDeadline + 1, -1);
    int totalTreasure = 0;

    for (const auto &sp : spells) {
        // Find the latest available slot
        int avail = findParent(parent, sp.deadline);
        if (avail > 0) {
            result[avail] = sp.id;
            totalTreasure += sp.treasure;
            // Link the taken slot to the previous slot (Union step)
            parent[avail] = findParent(parent, avail - 1);
        }
    }

    // Collect scheduled spell IDs in order of execution
    vector<int> scheduled;
    for (int i = 1; i <= maxDeadline; i++) {
        if (result[i] != -1) scheduled.push_back(result[i]);
    }

    return {scheduled, totalTreasure};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<Spell> spells(n);
        for (int i = 0; i < n; i++) {
            // Read: id deadline treasure
            cin >> spells[i].id >> spells[i].deadline >> spells[i].treasure;
        }

        auto res = solveQuest(spells);

        // Output scheduled spell IDs
        for (size_t i = 0; i < res.first.size(); i++) {
            cout << res.first[i] << (i == res.first.size() - 1 ? "" : " ");
        }
        cout << "\n";
        
        // Output total treasure
        cout << res.second << "\n";
    }

    return 0;
}