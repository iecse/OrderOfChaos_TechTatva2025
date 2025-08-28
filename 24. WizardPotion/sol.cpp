#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPotionStrength(vector<int>& vials) {
        int leftWizard = 0, rightWizard = vials.size() - 1;
        int strongestPotion = 0;

        while (leftWizard < rightWizard) {
            int distance = rightWizard - leftWizard;
            int essence = min(vials[leftWizard], vials[rightWizard]);
            strongestPotion = max(strongestPotion, distance * essence);

            // Move the wizard with the smaller vial inward
            if (vials[leftWizard] < vials[rightWizard]) {
                leftWizard++;
            } else {
                rightWizard--;
            }
        }
        return strongestPotion;
    }
};

