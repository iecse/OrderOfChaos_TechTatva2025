#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

bool hasDuplicate(const vector<int> &arr)
{
    unordered_set<int> seen;
    for (int power : arr)
    {
        if (seen.find(power) != seen.end())
        {
            return true;
        }
        seen.insert(power);
    }
    return false;
}

string solveTestCase(const vector<int> &powers)
{
    return hasDuplicate(powers) ? "YES" : "NO";
}

// Generate array with guaranteed duplicates
vector<int> generateWithDuplicates(int n)
{
    vector<int> arr(n);

    // First, fill with random values
    for (int i = 0; i < n; i++)
    {
        arr[i] = rnd.next(2, 100);
    }

    // Ensure at least one duplicate by copying a random element
    if (n >= 2)
    {
        int pos1 = rnd.next(0, n - 1);
        int pos2;
        do
        {
            pos2 = rnd.next(0, n - 1);
        } while (pos2 == pos1);

        arr[pos2] = arr[pos1];
    }

    return arr;
}

// Generate array with all unique values
vector<int> generateAllUnique(int n)
{
    vector<int> arr;
    set<int> used;

    while (arr.size() < n)
    {
        int val = rnd.next(2, 100);
        if (used.find(val) == used.end())
        {
            used.insert(val);
            arr.push_back(val);
        }
    }

    // Shuffle to randomize order
    shuffle(arr.begin(), arr.end());
    return arr;
}

// Generate random array (may or may not have duplicates)
vector<int> generateRandom(int n)
{
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rnd.next(2, 100);
    }
    return arr;
}

void writeTest(int z)
{
    string num = (z > 9) ? to_string(z) : "0" + to_string(z);
    fstream test;
    fstream answer;
    test.open("Input" + num + ".txt", ios::out);
    answer.open("Output" + num + ".txt", ios::out);

    int t;
    vector<pair<int, vector<int>>> testCases;

    if (z == 0) // Small cases and edge cases
    {
        t = 20;

        // Edge case: minimum n=2 with duplicates
        testCases.push_back({2, {2, 2}});
        testCases.push_back({2, {3, 3}});

        // Edge case: minimum n=2 without duplicates
        testCases.push_back({2, {2, 3}});
        testCases.push_back({2, {5, 7}});

        // Small cases with all same values
        testCases.push_back({3, {5, 5, 5}});
        testCases.push_back({4, {10, 10, 10, 10}});

        // Small cases with exactly one duplicate pair
        testCases.push_back({3, {2, 5, 2}});
        testCases.push_back({4, {3, 7, 9, 7}});

        // Small cases with all unique
        testCases.push_back({3, {2, 3, 4}});
        testCases.push_back({4, {2, 5, 8, 11}});

        // Boundary power values
        testCases.push_back({3, {2, 100, 2}});   // min and max power
        testCases.push_back({3, {99, 100, 98}}); // near max values

        // Generate remaining random small cases
        while (testCases.size() < t)
        {
            int n = rnd.next(2, 10);
            vector<int> arr;

            if (rnd.next(0, 1) == 0)
            {
                arr = generateWithDuplicates(n);
            }
            else
            {
                if (n <= 99) // can generate all unique only if n <= 99 (since power range is 2-100)
                    arr = generateAllUnique(n);
                else
                    arr = generateRandom(n);
            }
            testCases.push_back({n, arr});
        }
    }
    else if (z == 1) // Medium cases
    {
        t = 50;

        // Cases with many duplicates
        for (int i = 0; i < 5; i++)
        {
            int n = rnd.next(10, 50);
            testCases.push_back({n, generateWithDuplicates(n)});
        }

        // Cases with all unique (when possible)
        for (int i = 0; i < 5; i++)
        {
            int n = rnd.next(10, min(50, 99)); // can't have more than 99 unique values
            testCases.push_back({n, generateAllUnique(n)});
        }

        // Mixed random cases
        while (testCases.size() < t)
        {
            int n = rnd.next(5, 60);
            testCases.push_back({n, generateRandom(n)});
        }
    }
    else // z == 2: Large cases
    {
        t = 100;

        // Maximum n cases
        for (int i = 0; i < 10; i++)
        {
            testCases.push_back({100, generateWithDuplicates(100)});
        }

        // Large cases with all unique (n <= 99)
        for (int i = 0; i < 5; i++)
        {
            int n = rnd.next(90, 99);
            testCases.push_back({n, generateAllUnique(n)});
        }

        // Edge case: exactly 99 unique values
        testCases.push_back({99, generateAllUnique(99)});

        // Large random cases
        while (testCases.size() < t)
        {
            int n = rnd.next(50, 100);
            testCases.push_back({n, generateRandom(n)});
        }
    }

    test << t << endl;

    for (auto &tc : testCases)
    {
        int n = tc.first;
        vector<int> &powers = tc.second;

        test << n << endl;
        for (int i = 0; i < n; i++)
        {
            test << powers[i];
            if (i < n - 1)
                test << " ";
        }
        test << endl;

        answer << solveTestCase(powers) << endl;
    }

    test.close();
    answer.close();
}

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    for (int no = 0; no < 3; no++)
        writeTest(no);
    return 0;
}