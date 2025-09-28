#include <iostream>
#include <vector>
#include <unordered_set>
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

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> powers(n);

        for (int i = 0; i < n; i++)
        {
            cin >> powers[i];
        }

        if (hasDuplicate(powers))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}