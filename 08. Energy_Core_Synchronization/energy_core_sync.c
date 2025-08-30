#include <stdio.h>

int main() {
    int t;
    printf("")
    scanf("%d", &t);
    while (t--) {
        long long x;
        scanf("%lld", &x);

        int bits = 0;
        long long temp = x;
        while (temp > 0) {
            bits++;
            temp >>= 1; // divide by 2
        }

        // answer is number of bits + 2
        printf("%d\n", bits + 2);
    }
    return 0;
}
