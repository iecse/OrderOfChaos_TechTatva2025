#include <bits/stdc++.h>
using namespace std;

int trappedEnchantedWater(vector<int>& height, vector<int>& leak) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> leftMax(n), rightMax(n);

    // Left max for each pillar
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    // Right max for each pillar
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    // Calculate enchanted water
    int total = 0;
    for (int i = 0; i < n; i++) {
        in
