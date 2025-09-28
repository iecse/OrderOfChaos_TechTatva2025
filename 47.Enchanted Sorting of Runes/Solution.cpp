// Solution.hpp
#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <bits/stdc++.h>
using namespace std;

// Solution function: magicalSorting
vector<int> magicalSorting(const vector<int>& nums) {
    vector<int> evens, odds;

    // Step 1: Separate the runes
    for (int x : nums) {
        if (x % 2 == 0) evens.push_back(x);  // Rune of Balance ⚖️
        else odds.push_back(x);              // Rune of Fire 🔥
    }

    // Step 2: Sort with enchantments
    sort(evens.begin(), evens.end());                  // Ascending order
    sort(odds.begin(), odds.end(), greater<int>());    // Descending order

    // Step 3: Rebuild the enchanted array
    vector<int> result;
    int ei = 0, oi = 0;
    for (int x : nums) {
        if (x % 2 == 0) result.push_back(evens[ei++]);
        else result.push_back(odds[oi++]);
    }

    return result;
}

#endif
