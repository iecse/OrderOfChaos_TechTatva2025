#include "../testlib.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// Solution function to generate expected outputs
long long countSacredPathways(int n, long long totalEnergy, int peakEnergy, const vector<int> &energy)
{
    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        prefix[i] = prefix[i - 1] + energy[i];
    }

    long long ritualCount = 0;
    unordered_map<long long, int> prefixCount;
    int leftBound = 1;

    for (int right = 1; right <= n; ++right)
    {
        if (energy[right] > peakEnergy)
        {
            prefixCount.clear();
            leftBound = right + 1;
        }
        else if (energy[right] == peakEnergy)
        {
            while (leftBound <= right)
            {
                long long key = prefix[leftBound - 1];
                ++prefixCount[key];
                ++leftBound;
            }
        }

        long long targetPrefix = prefix[right] - totalEnergy;
        auto it = prefixCount.find(targetPrefix);
        if (it != prefixCount.end())
        {
            ritualCount += it->second;
        }
    }

    return ritualCount;
}

void writeTest(int z)
{
    string inputFile = "Input" + (z > 9 ? to_string(z) : "0" + to_string(z)) + ".txt";
    string outputFile = "Output" + (z > 9 ? to_string(z) : "0" + to_string(z)) + ".txt";

    freopen(inputFile.c_str(), "w", stdout);

    int t;
    vector<vector<int>> testCases;
    vector<long long> targetSums;
    vector<int> targetPeaks;

    if (z == 0)
    {
        // Test case 0: Small cases and edge cases
        t = 5;
        cout << t << endl;

        // Case 1: Single element matching both conditions
        int n1 = 1;
        long long s1 = 5;
        int p1 = 5;
        vector<int> energy1 = {0, 5}; // 1-indexed
        cout << n1 << " " << s1 << " " << p1 << endl;
        for (int i = 1; i <= n1; i++)
        {
            cout << energy1[i] << (i == n1 ? "\n" : " ");
        }
        testCases.push_back(energy1);
        targetSums.push_back(s1);
        targetPeaks.push_back(p1);

        // Case 2: Two elements, one valid subarray
        int n2 = 3;
        long long s2 = 10;
        int p2 = 7;
        vector<int> energy2 = {0, 3, 7, 2}; // sum [3,7] = 10, max = 7
        cout << n2 << " " << s2 << " " << p2 << endl;
        for (int i = 1; i <= n2; i++)
        {
            cout << energy2[i] << (i == n2 ? "\n" : " ");
        }
        testCases.push_back(energy2);
        targetSums.push_back(s2);
        targetPeaks.push_back(p2);

        // Case 3: No valid pathways
        int n3 = 3;
        long long s3 = 15;
        int p3 = 5;
        vector<int> energy3 = {0, 2, 3, 4}; // no subarray sums to 15 with max 5
        cout << n3 << " " << s3 << " " << p3 << endl;
        for (int i = 1; i <= n3; i++)
        {
            cout << energy3[i] << (i == n3 ? "\n" : " ");
        }
        testCases.push_back(energy3);
        targetSums.push_back(s3);
        targetPeaks.push_back(p3);

        // Case 4: Negative numbers
        int n4 = 4;
        long long s4 = -2;
        int p4 = 3;
        vector<int> energy4 = {0, -5, 3, 1, -1}; // subarray [3,1,-1] = 3, max = 3
        cout << n4 << " " << s4 << " " << p4 << endl;
        for (int i = 1; i <= n4; i++)
        {
            cout << energy4[i] << (i == n4 ? "\n" : " ");
        }
        testCases.push_back(energy4);
        targetSums.push_back(s4);
        targetPeaks.push_back(p4);

        // Case 5: Multiple valid pathways
        int n5 = 5;
        long long s5 = 6;
        int p5 = 3;
        vector<int> energy5 = {0, 3, 3, 1, 2, 3}; // multiple subarrays sum to 6 with max 3
        cout << n5 << " " << s5 << " " << p5 << endl;
        for (int i = 1; i <= n5; i++)
        {
            cout << energy5[i] << (i == n5 ? "\n" : " ");
        }
        testCases.push_back(energy5);
        targetSums.push_back(s5);
        targetPeaks.push_back(p5);
    }
    else if (z == 1)
    {
        // Test case 1: Medium cases with various scenarios
        t = 3;
        cout << t << endl;

        // Case 1: Random medium size
        int n1 = rnd.next(50, 100);
        int p1 = rnd.next(-1000, 1000);
        long long s1 = rnd.next(-1000000LL, 1000000LL);
        vector<int> energy1(n1 + 1);
        energy1[0] = 0;

        cout << n1 << " " << s1 << " " << p1 << endl;
        for (int i = 1; i <= n1; i++)
        {
            energy1[i] = rnd.next(-1000, 1000);
            cout << energy1[i] << (i == n1 ? "\n" : " ");
        }
        testCases.push_back(energy1);
        targetSums.push_back(s1);
        targetPeaks.push_back(p1);

        // Case 2: Ensure some elements equal to p
        int n2 = rnd.next(30, 80);
        int p2 = rnd.next(-500, 500);
        long long s2 = rnd.next(-500000LL, 500000LL);
        vector<int> energy2(n2 + 1);
        energy2[0] = 0;

        cout << n2 << " " << s2 << " " << p2 << endl;
        for (int i = 1; i <= n2; i++)
        {
            if (rnd.next(1, 5) == 1)
            {
                energy2[i] = p2; // 20% chance to be exactly p
            }
            else
            {
                energy2[i] = rnd.next(-1000, min(1000, p2)); // ensure <= p
            }
            cout << energy2[i] << (i == n2 ? "\n" : " ");
        }
        testCases.push_back(energy2);
        targetSums.push_back(s2);
        targetPeaks.push_back(p2);

        // Case 3: Large positive numbers
        int n3 = rnd.next(40, 90);
        int p3 = rnd.next(100000, 1000000000);
        long long s3 = rnd.next(1000000LL, 1000000000LL);
        vector<int> energy3(n3 + 1);
        energy3[0] = 0;

        cout << n3 << " " << s3 << " " << p3 << endl;
        for (int i = 1; i <= n3; i++)
        {
            energy3[i] = rnd.next(1, min(1000000000, p3));
            cout << energy3[i] << (i == n3 ? "\n" : " ");
        }
        testCases.push_back(energy3);
        targetSums.push_back(s3);
        targetPeaks.push_back(p3);
    }
    else
    { // z == 2
        // Test case 2: Large cases near constraints
        t = 2;
        cout << t << endl;

        // Case 1: Large array with diverse values
        int n1 = rnd.next(1500, 2000);
        int p1 = rnd.next(-1000000000, 1000000000);
        long long s1 = rnd.next(-200000000000000LL, 200000000000000LL);
        vector<int> energy1(n1 + 1);
        energy1[0] = 0;

        cout << n1 << " " << s1 << " " << p1 << endl;
        for (int i = 1; i <= n1; i++)
        {
            energy1[i] = rnd.next(-1000000000, min(1000000000, p1));
            cout << energy1[i] << (i == n1 ? "\n" : " ");
        }
        testCases.push_back(energy1);
        targetSums.push_back(s1);
        targetPeaks.push_back(p1);

        // Case 2: Maximum constraints stress test
        int n2 = rnd.next(1800, 2000);
        int p2 = 1000000000; // max p
        long long s2 = rnd.next(-100000000000000LL, 100000000000000LL);
        vector<int> energy2(n2 + 1);
        energy2[0] = 0;

        cout << n2 << " " << s2 << " " << p2 << endl;
        // Ensure at least some elements are exactly p2
        for (int i = 1; i <= n2; i++)
        {
            if (i <= 5)
            {
                energy2[i] = p2; // First few elements are max
            }
            else
            {
                energy2[i] = rnd.next(-1000000000, p2);
            }
            cout << energy2[i] << (i == n2 ? "\n" : " ");
        }
        testCases.push_back(energy2);
        targetSums.push_back(s2);
        targetPeaks.push_back(p2);
    }

    fclose(stdout);

    // Generate output file
    freopen(outputFile.c_str(), "w", stdout);

    for (int i = 0; i < testCases.size(); i++)
    {
        long long result = countSacredPathways(testCases[i].size() - 1, targetSums[i], targetPeaks[i], testCases[i]);
        cout << result << endl;
    }

    fclose(stdout);
}

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    for (int no = 0; no < 3; no++)
    {
        writeTest(no);
    }

    return 0;
}