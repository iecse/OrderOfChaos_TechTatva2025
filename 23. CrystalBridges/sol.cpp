#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, s;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<Edge>> adj(n + 1);

        for (int i = 0; i < m; i++) {
            int u, v, s;
            cin >> u >> v >> s;
            adj[u].push_back({v, s});
            adj[v].push_back({u, s});
        }

        // dist[node] = minimum days required to reach node
        vector<int> dist(n + 1, INT_MAX);
        queue<pair<int, int>> q; // (node, days)
        q.push({1, 0});
        dist[1] = 0;

        bool possible = false;

        while (!q.empty()) {
            auto [u, days] = q.front();
            q.pop();

            if (u == n) {
                possible = true;
                break;
            }

            for (auto &edge : adj[u]) {
                int v = edge.to;
                int stability = edge.s;

                // Next edge requires stability >= days+1
                if (stability >= days + 1 && dist[v] > days + 1) {
                    dist[v] = days + 1;
                    q.push({v, days + 1});
                }
            }
        }

        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}
