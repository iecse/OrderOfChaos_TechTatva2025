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
    int n;
    cout << "Enter number of spells: ";
    cin >> n;

    vector<Spell> spells(n);
    cout << "Enter spell details (id deadline treasure) each in new line:\n";
    for (int i = 0; i < n; i++) {
        cin >> spells[i].id >> spells[i].deadline >> spells[i].treasure;
    }

    auto res = enchantedQuest(spells, n);

    cout << "Chosen Spells: [";
    for (int id : res.first) cout << id << " ";
    cout << "], Total Treasure: " << res.second << endl;

    return 0;
}
