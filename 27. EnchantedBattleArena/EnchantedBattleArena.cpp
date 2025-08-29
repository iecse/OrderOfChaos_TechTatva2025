#include <cstdio>
#include <algorithm>
#include <cstring>

#define S 100005

typedef long long ll;

ll a[S], d[S], n;

bool check(ll men)
{
    memset(d, 0, sizeof(ll) * n);
    ll acc = 0;

    for (ll i = 0; i < n; ++i)
    {
        acc -= d[i];

        ll need = std::max(0LL, i - (n - men));
        if (acc < need)
            return false;

        ll end = i + a[i] + (acc++) - need + 1;
        if (end < n)
            ++d[end];
    }

    return true;
}

void solve()
{
    scanf("%lld", &n);
    for (ll i = 0; i < n; ++i)
        scanf("%lld", &a[i]);

    ll left = 1, right = n + 1, mid;
    while (right - left > 1)
    {
        mid = (left + right) / 2;
        if (check(mid))
            left = mid;
        else
            right = mid;
    }

    printf("%lld\n", left);
}

int main()
{
    ll tc;
    scanf("%lld", &tc);
    while (tc--)
        solve();
}