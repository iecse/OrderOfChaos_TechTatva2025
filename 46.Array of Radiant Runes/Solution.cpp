#include <bits/stdc++.h>
using namespace std;

vector<int> radiantRunes(vector<int>& nums) {
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

int main() {
    vector<int> nums1 = {3,7,1,7,8,4};
    vector<int> ans1 = radiantRunes(nums1);
    for (int x : ans1) cout << x << " ";
    cout << endl;

    vector<int> nums2 = {5,3,20,15,8};
    vector<int> ans2 = radiantRunes(nums2);
    for (int x : ans2) cout << x << " ";
    cout << endl;

    vector<int> nums3 = {1,2,3,4,5};
    vector<int> ans3 = radiantRunes(nums3);
    for (int x : ans3) cout << x << " ";
    cout << endl;

    return 0;
}
