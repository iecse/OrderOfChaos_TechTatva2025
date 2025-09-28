#include "../testlib.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Solution function
long long answer(int n, const string &alpha, const string &beta)
{
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = alpha[i] - '0';
        b[i] = beta[i] - '0';
    }

    vector<long long> prea(n + 1, 0), preb(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        prea[i + 1] = prea[i] + (a[i] == 0 ? 1 : -1);
        preb[i + 1] = preb[i] + (b[i] == 1 ? 1 : -1);
    }

    long long total_basic_sum = (long long)n * n * (n + 1) / 2;

    vector<long long> sorted_prea(prea.begin() + 1, prea.end());
    vector<long long> sorted_preb(preb.begin() + 1, preb.end());
    sort(sorted_prea.begin(), sorted_prea.end());
    sort(sorted_preb.begin(), sorted_preb.end());

    long long abs_diff_sum = 0;

    for (int i = 0; i < n; i++)
    {
        long long curr_prea = sorted_prea[i];

        int smaller_count = lower_bound(sorted_preb.begin(), sorted_preb.end(), curr_prea) - sorted_preb.begin();

        abs_diff_sum += curr_prea * smaller_count;
        abs_diff_sum -= curr_prea * (n - smaller_count);
    }

    for (int i = 0; i < n; i++)
    {
        long long curr_preb = sorted_preb[i];

        int smaller_equal_count = upper_bound(sorted_prea.begin(), sorted_prea.end(), curr_preb) - sorted_prea.begin();

        abs_diff_sum += curr_preb * smaller_equal_count;
        abs_diff_sum -= curr_preb * (n - smaller_equal_count);
    }

    long long result = total_basic_sum - abs_diff_sum / 2;
    return result;
}

// Generate a random binary string of length n
string generateBinaryString(int n)
{
    string result = "";
    for (int i = 0; i < n; i++)
    {
        result += (rnd.next(2) == 0) ? '0' : '1';
    }
    return result;
}

// Generate specific pattern binary strings for edge cases
string generateAllZeros(int n)
{
    return string(n, '0');
}

string generateAllOnes(int n)
{
    return string(n, '1');
}

string generateAlternating(int n, bool startWithZero = true)
{
    string result = "";
    for (int i = 0; i < n; i++)
    {
        if (startWithZero)
        {
            result += (i % 2 == 0) ? '0' : '1';
        }
        else
        {
            result += (i % 2 == 0) ? '1' : '0';
        }
    }
    return result;
}

void writeTest(int z)
{
    string inputFileName = "Input" + (z > 9 ? to_string(z) : "0" + to_string(z)) + ".txt";
    string outputFileName = "Output" + (z > 9 ? to_string(z) : "0" + to_string(z)) + ".txt";

    freopen(inputFileName.c_str(), "w", stdout);

    vector<pair<int, pair<string, string>>> testCases;

    if (z == 0)
    {
        // Test case 0: Small cases and edge cases

        // Single element cases
        testCases.push_back({1, {"0", "0"}});
        testCases.push_back({1, {"0", "1"}});
        testCases.push_back({1, {"1", "0"}});
        testCases.push_back({1, {"1", "1"}});

        // Small cases with patterns
        testCases.push_back({2, {"00", "00"}});
        testCases.push_back({2, {"11", "11"}});
        testCases.push_back({2, {"01", "10"}});
        testCases.push_back({3, {"000", "111"}});
        testCases.push_back({3, {"101", "010"}});

        // Slightly larger edge cases
        testCases.push_back({5, {generateAllZeros(5), generateAllOnes(5)}});
        testCases.push_back({4, {generateAlternating(4, true), generateAlternating(4, false)}});
    }
    else if (z == 1)
    {
        // Test case 1: Medium cases with various patterns

        // Medium random cases
        for (int i = 0; i < 3; i++)
        {
            int n = rnd.next(10, 100);
            testCases.push_back({n, {generateBinaryString(n), generateBinaryString(n)}});
        }

        // Medium cases with specific patterns
        testCases.push_back({50, {generateAllZeros(50), generateBinaryString(50)}});
        testCases.push_back({75, {generateBinaryString(75), generateAllOnes(75)}});
        testCases.push_back({30, {generateAlternating(30, true), generateAlternating(30, true)}});

        // Cases with mostly same values but some different
        int n = 60;
        string alpha = generateAllZeros(n);
        string beta = generateAllZeros(n);
        // Change a few positions
        for (int i = 0; i < 5; i++)
        {
            int pos = rnd.next(n);
            alpha[pos] = '1';
            pos = rnd.next(n);
            beta[pos] = '1';
        }
        testCases.push_back({n, {alpha, beta}});
    }
    else
    {
        // Test case 2: Large cases near constraints

        // Large random cases
        for (int i = 0; i < 2; i++)
        {
            int n = rnd.next(100000, 200000);
            testCases.push_back({n, {generateBinaryString(n), generateBinaryString(n)}});
        }

        // Maximum constraint case
        int maxN = 200000;
        testCases.push_back({maxN, {generateBinaryString(maxN), generateBinaryString(maxN)}});

        // Large cases with patterns
        int largeN = 150000;
        testCases.push_back({largeN, {generateAllZeros(largeN), generateAllOnes(largeN)}});
        testCases.push_back({largeN, {generateAlternating(largeN, true), generateAlternating(largeN, false)}});

        // Large case with mixed pattern
        string largeMixed1 = "";
        string largeMixed2 = "";
        for (int i = 0; i < largeN; i++)
        {
            if (i < largeN / 3)
            {
                largeMixed1 += '0';
                largeMixed2 += '1';
            }
            else if (i < 2 * largeN / 3)
            {
                largeMixed1 += (i % 2 == 0) ? '0' : '1';
                largeMixed2 += (i % 2 == 0) ? '1' : '0';
            }
            else
            {
                largeMixed1 += (rnd.next(2) == 0) ? '0' : '1';
                largeMixed2 += (rnd.next(2) == 0) ? '0' : '1';
            }
        }
        testCases.push_back({largeN, {largeMixed1, largeMixed2}});
    }

    // Output the test cases
    cout << testCases.size() << "\n";
    for (auto &tc : testCases)
    {
        cout << tc.first << "\n";
        cout << tc.second.first << "\n";
        cout << tc.second.second << "\n";
    }

    fclose(stdout);

    // Generate output file
    freopen(outputFileName.c_str(), "w", stdout);

    for (auto &tc : testCases)
    {
        cout << answer(tc.first, tc.second.first, tc.second.second) << "\n";
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