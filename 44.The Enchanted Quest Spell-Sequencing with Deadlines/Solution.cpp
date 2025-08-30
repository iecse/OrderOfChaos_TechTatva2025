#include <bits/stdc++.h>
using namespace std;

struct Spell {
    int id;        // Rune of Identity
    int deadline;  // Deadline Sigil
    int treasure;  // Treasure Value
};

// Custom comparator for sorting spells by treasure (descending)
bool cmp(Spell a, Spell b) {
    return a.treasure > b.treasure;
}

pair<vector<int>, int> enchantedQuest(vector<Spell>& spells, int n) {
    // Step 1: Sort by treasure value
    sort(spells.begin(), spells.end(), cmp);

    // Step 2: Find max deadline to size timeline
    int maxDeadline = 0;
    for (auto &s : spells) {
        maxDeadline = max(maxDeadline, s.deadline);
    }

    // Step 3: Create time slots (0 = empty)
    vector<int> slot(maxDeadline + 1, -1);
    vector<int> chosenSpells;
    int totalTreasure = 0;

    // Step 4: Place each spell in the latest possible slot
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

int main() {
    // Example 1
    vector<Spell> spells1 = {{1,4,20}, {2,1,10}, {3,1,40}, {4,1,30}};
    auto res1 = enchantedQuest(spells1, 4);
    cout << "[";
    for (int id : res1.first) cout << id << " ";
    cout << "], " << res1.second << endl; // [3 1], 60

    // Example 2
    vector<Spell> spells2 = {{1,2,100}, {2,1,19}, {3,2,27}, {4,1,25}, {5,1,15}};
    auto res2 = enchantedQuest(spells2, 5);
    cout << "[";
    for (int id : res2.first) cout << id << " ";
    cout << "], " << res2.second << endl; // [1 3], 127

    // Example 3
    vector<Spell> spells3 = {{1,3,15}, {2,2,20}, {3,1,30}};
    auto res3 = enchantedQuest(spells3, 3);
    cout << "[";
    for (int id : res3.first) cout << id << " ";
    cout << "], " << res3.second << endl; // [3 2 1], 65

    return 0;
}
