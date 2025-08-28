#include <bits/stdc++.h>
using namespace std;

void mergeScrolls(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;       // Last element of actual runes in nums1
    int j = n - 1;       // Last element in nums2
    int k = m + n - 1;   // Last slot in nums1

    // Merge from the back
    while(i >= 0 && j >= 0) {
        if(nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // Copy remaining runes from nums2, if any
    while(j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    vector<int> nums1 = {1,3,5,0,0,0}; // Golden Scroll
    int m = 3;
    vector<int> nums2 = {2,4,6};       // Silver Scroll
    int n = 3;

    mergeScrolls(nums1, m, nums2, n);

    for(int rune : nums1) {
        cout << rune << " ";
    }
    cout << endl;

    return 0;
}
