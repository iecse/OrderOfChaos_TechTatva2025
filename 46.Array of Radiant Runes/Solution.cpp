// Solution.hpp
#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <bits/stdc++.h>
using namespace std;

// Solution function: returns the radiant runes
vector<int> radiantRunes(const vector<int>& nums) {
    vector<int> result;
    int maxRight = INT_MIN;  // the brightest rune seen so far from the right

    // Traverse from right to left
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (nums[i] > maxRight) {
            result.push_back(nums[i]);   // this rune is radiant ✨
            maxRight = nums[i];
        }
    }

    // Reverse to restore original order
    reverse(result.begin(), result.end());
    return result;
}

#endif
