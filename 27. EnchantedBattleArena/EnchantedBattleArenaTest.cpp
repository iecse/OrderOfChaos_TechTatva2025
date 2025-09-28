#include "../testlib.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

// Solution function - implements the binary search + greedy check
bool check(vector<ll> &a, ll men)
{
    ll n = a.size();
    vector<ll> d(n, 0);
    ll acc = 0;

    for (ll i = 0; i < n; ++i)
    {
        acc -= d[i];

        ll need = max(0LL, i - (n - men));
        if (acc < need)
            return false;

        ll end = i + a[i] + (acc++) - need + 1;
        if (end < n)
            ++d[end];
    }

    return true;
}

ll solve(vector<ll> &a)
{
    ll n = a.size();
    ll left = 1, right = n + 1, mid;

    while (right - left > 1)
    {
        mid = (left + right) / 2;
        if (check(a, mid))
            left = mid;
        else
            right = mid;
    }

    return left;
}

void writeTest(int z)
{
    string inputFileName = "Input" + (z > 9 ? to_string(z) : "0" + to_string(z)) + ".txt";
    string outputFileName = "Output" + (z > 9 ? to_string(z) : "0" + to_string(z)) + ".txt";

    ofstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    int t;
    vector<vector<ll>> testCases;

    if (z == 0)
    {
        // Test case 0: Small cases and edge cases
        t = 5;

        // Case 1: Single warrior with 0 power
        testCases.push_back({0});

        // Case 2: Single warrior with positive power
        testCases.push_back({3});

        // Case 3: Two warriors, both zero
        testCases.push_back({0, 0});

        // Case 4: Two warriors, simple case
        testCases.push_back({1, 2});

        // Case 5: All zeros
        testCases.push_back({0, 0, 0, 0});
    }
    else if (z == 1)
    {
        // Test case 1: Medium cases with various patterns
        t = 4;

        // Case 1: Ascending pattern
        testCases.push_back({1, 2, 3, 4, 5});

        // Case 2: Descending pattern
        testCases.push_back({5, 4, 3, 2, 1});

        // Case 3: Mixed pattern requiring careful ordering
        testCases.push_back({3, 1, 4, 1, 5, 9, 2, 6});

        // Case 4: Large values but small array
        testCases.push_back({1000000, 999999, 1000000});
    }
    else
    {
        // Test case 2: Larger cases within constraints
        t = 3;

        // Case 1: Random medium-sized array
        int n1 = rnd.next(15, 25);
        vector<ll> case1(n1);
        for (int i = 0; i < n1; i++)
        {
            case1[i] = rnd.next(0LL, 100LL);
        }
        testCases.push_back(case1);

        // Case 2: Large array with moderate values
        int n2 = rnd.next(40, 60);
        vector<ll> case2(n2);
        for (int i = 0; i < n2; i++)
        {
            case2[i] = rnd.next(0LL, 1000LL);
        }
        testCases.push_back(case2);

        // Case 3: Maximum constraints test
        int n3 = rnd.next(80, 100);
        vector<ll> case3(n3);
        for (int i = 0; i < n3; i++)
        {
            // Mix of different value ranges
            if (rnd.next(3) == 0)
            {
                case3[i] = 0; // Some zeros
            }
            else if (rnd.next(3) == 0)
            {
                case3[i] = rnd.next(1LL, 100LL); // Small values
            }
            else if (rnd.next(2) == 0)
            {
                case3[i] = rnd.next(1000LL, 100000LL); // Medium values
            }
            else
            {
                case3[i] = rnd.next(100000LL, 1000000000LL); // Large values
            }
        }
        testCases.push_back(case3);
    }

    // Write input file
    inputFile << t << "\n";
    for (auto &testCase : testCases)
    {
        inputFile << testCase.size() << "\n";
        for (int i = 0; i < (int)testCase.size(); i++)
        {
            if (i > 0)
                inputFile << " ";
            inputFile << testCase[i];
        }
        inputFile << "\n";
    }

    // Generate output using solution
    for (auto &testCase : testCases)
    {
        ll result = solve(testCase);
        outputFile << result << "\n";
    }

    inputFile.close();
    outputFile.close();
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