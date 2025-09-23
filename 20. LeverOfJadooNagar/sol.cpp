#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        int iterations = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] > b[i]) iterations += (a[i] - b[i]);
        }

        cout << iterations << endl;
    }
    return 0;
}
