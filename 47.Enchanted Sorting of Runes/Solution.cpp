#include <bits/stdc++.h>
using namespace std;

vector<int> magicalSorting(vector<int>& nums) {
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

int main() {
    vector<int> nums1 = {5, 2, 8, 7, 1, 4};
    vector<int> ans1 = magicalSorting(nums1);
    for (int x : ans1) cout << x << " ";
    cout << endl;

    vector<int> nums2 = {9, 4, 1, 6, 3, 8};
    vector<int> ans2 = magicalSorting(nums2);
    for (int x : ans2) cout << x << " ";
    cout << endl;

    vector<int> nums3 = {10, 21, 32, 43, 54};
    vector<int> ans3 = magicalSorting(nums3);
    for (int x : ans3) cout << x << " ";
    cout << endl;

    return 0;
}
