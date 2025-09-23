#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int first, second;
} Pair;

int cmpPair(const void *p1, const void *p2) {
    Pair *a = (Pair*)p1;
    Pair *b = (Pair*)p2;
    if(a->first != b->first) return a->first - b->first;
    return a->second - b->second;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);

    int a[n+1];
    Pair vec[n];

    for(int i=1;i<=n;i++) scanf("%d", &a[i]);

    long long ans = 0;
    for(int i=1;i<=n;i++) {
        int b;
        scanf("%d", &b);
        if(b < a[i]) {
            int tmp = a[i];
            a[i] = b;
            b = tmp;
        }
        ans += (long long)(b - a[i]);
        vec[i-1].first = a[i];
        vec[i-1].second = b;
    }

    qsort(vec, n, sizeof(Pair), cmpPair);

    for(int i=1;i<n;i++) {
        if(vec[i].first <= vec[i-1].second) {
            printf("%lld\n", ans);
            return;
        }
    }

    int mn = 2000000000; // 2e9
    for(int i=1;i<n;i++) {
        int diff = vec[i].first - vec[i-1].second;
        if(diff < mn) mn = diff;
    }

    printf("%lld\n", ans + 2LL * mn);
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) solve();
    return 0;
}
