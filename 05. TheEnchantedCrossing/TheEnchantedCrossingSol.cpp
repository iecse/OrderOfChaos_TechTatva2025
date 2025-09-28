#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function: how many travelers cross the bridge
int enchantedCrossing(vector<int>& tiles, const vector<int>& travelers) {
    int n = tiles.size();
    int m = travelers.size();
    int crossed = 0;

    for (int j = 0; j < m; j++) {
        int w = travelers[j];

        // search from leftmost tile
        for (int i = 0; i < n; i++) {
            if (tiles[i] >= w) {
                tiles[i] -= w;
                crossed++;
                break;
            }
        }
    }

    return crossed;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; // number of test cases
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> tiles(n), travelers(m);
        for (int i = 0; i < n; i++) cin >> tiles[i];
        for (int j = 0; j < m; j++) cin >> travelers[j];

        cout << enchantedCrossing(tiles, travelers) << "\n";
    }

    return 0;
}
