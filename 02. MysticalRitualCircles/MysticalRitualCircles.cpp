#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to count sacred pathways for one test case
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, peakEnergy;
        long long totalEnergy;
        cin >> n >> totalEnergy >> peakEnergy;

        vector<int> energy(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> energy[i];
        }

        cout << countSacredPathways(n, totalEnergy, peakEnergy, energy) << '\n';
    }

    return 0;
}
