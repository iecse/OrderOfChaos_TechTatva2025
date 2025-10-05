#include <bits/stdc++.h>
using namespace std;

struct Spell {
    int id, deadline, treasure;
};

// Iterative DSU find (fast, non-recursive)
int findp(int x, vector<int> &parent) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

pair<vector<int>, long long> solveQuest(vector<Spell> &spells) {
    // Sort by treasure desc; tie-breaker: smaller id first
    sort(spells.begin(), spells.end(), [](const Spell &a, const Spell &b) {
        if (a.treasure != b.treasure) return a.treasure > b.treasure;
        return a.id < b.id;
    });

    int n = (int)spells.size();
    int maxD = 0;
    for (auto &s : spells) maxD = max(maxD, s.deadline);
    maxD = min(maxD, n);

    vector<int> parent(maxD + 1);
    iota(parent.begin(), parent.end(), 0);
    vector<int> assigned(maxD + 1, -1);

    long long total = 0;
    for (auto &s : spells) {
        int d = min(s.deadline, maxD);
        int slot = findp(d, parent);
        if (slot > 0) {
            assigned[slot] = s.id;
            total += s.treasure;
            parent[slot] = findp(slot - 1, parent);
        }
    }

    vector<int> seq;
    seq.reserve(maxD);
    for (int i = 1; i <= maxD; ++i)
        if (assigned[i] != -1) seq.push_back(assigned[i]);

    return {seq, total};
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
        for (int i = 0; i < n; ++i)
            cin >> spells[i].id >> spells[i].deadline >> spells[i].treasure;

        auto res = solveQuest(spells);

        for (size_t i = 0; i < res.first.size(); ++i) {
            if (i) cout << ' ';
            cout << res.first[i];
        }
        cout << '\n' << res.second << '\n';
    }
    return 0;
}
