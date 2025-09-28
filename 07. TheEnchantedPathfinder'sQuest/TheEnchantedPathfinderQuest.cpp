#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string alpha, beta;
        cin >> n >> alpha >> beta;

        cout << answer(n, alpha, beta) << "\n";
    }

    return 0;
}
