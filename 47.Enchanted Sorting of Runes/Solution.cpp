// Solution.hpp
#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <vector>     
#include <algorithm>  
#include <functional>
using namespace std;

// Solution function: magicalSorting
vector<int> magicalSorting(const vector<int>& nums) {
    vector<int> evens, odds;

    // Step 1: Separate the runes
    for (int x : nums) {
        if (x % 2 == 0) evens.push_back(x);  
        else odds.push_back(x);              
    }

   
    sort(evens.begin(), evens.end());                  
    sort(odds.begin(), odds.end(), greater<int>());    

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
