#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Compute minimum k such that sum(ceil(ci/k)) <= H
ll compute_min_k(const vector<ll>& caches, ll H) {
    ll l = 1;
    ll r = 0;
    for (ll x : caches) r = max(r, x);
    ll ans = r;
    while (l <= r) {
        ll m = l + (r - l) / 2;
        long long total = 0; // 64-bit is enough for given constraints
        for (ll x : caches) {
            total += (x + m - 1) / m;
            if (total > H) break; // small optimization
        }
        if (total <= H) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans;
}

// Generate a single test file pair (InputXX.txt, OutputXX.txt)
void writeTest(int id) {
    string sid = (id > 9) ? to_string(id) : string("0") + to_string(id);
    fstream fin("Input" + sid + ".txt", ios::out);
    fstream fout("Output" + sid + ".txt", ios::out);

    int T = rnd.next(1, 200); // number of testcases in this file
    fin << T << "\n";

    int total_n = 0;
    for (int tc = 0; tc < T; ++tc) {
        int remaining = max(1, 10000 - total_n);
        int n = rnd.next(1, min(1000, remaining));
        total_n += n;

        vector<ll> caches(n);
        for (int i = 0; i < n; ++i) {
            int mode = rnd.next(1, 3);
            if (mode == 1) caches[i] = rnd.next(1, 100);           // small
            else if (mode == 2) caches[i] = rnd.next(100, 100000); // medium
            else caches[i] = rnd.next(100000, 1000000000);         // large
        }

        ll sum = 0, mx = 0;
        for (ll v : caches) { sum += v; mx = max(mx, v); }

        ll H;
        int pick = rnd.next(1, 5);
        if (pick == 1) H = n; // tight
        else if (pick == 2) H = rnd.next(n, (int)min<ll>(n + 50, 100000));
        else if (pick == 3) H = rnd.next(max<ll>(n, mx / 2), max<ll>(n, mx));
        else if (pick == 4) H = rnd.next(max<ll>(n, 1), min<ll>(1000000, sum));
        else H = rnd.next(max<ll>(n, 1), (ll)1e9);

        fin << n << " " << H << "\n";
        for (int i = 0; i < n; ++i) {
            fin << caches[i] << (i + 1 == n ? "\n" : " ");
        }

        ll ans = compute_min_k(caches, H);
        fout << ans << "\n";
    }

    fin.close();
    fout.close();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    // generate 3 files (00..02)
    for (int i = 0; i < 3; ++i) writeTest(i);
    return 0;
}
