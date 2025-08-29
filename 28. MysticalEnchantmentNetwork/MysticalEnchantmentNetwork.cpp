#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> color;
vector<bool> isTreeEdge;
vector<pair<int, int>> edges;
vector<int> parent, depth;
vector<vector<int>> up;
int LOG_N;

void dfs(int v, int p, int c, int d)
{
    color[v] = c;
    parent[v] = p;
    depth[v] = d;

    for (auto edge : adj[v])
    {
        int u = edge.first;
        int idx = edge.second;

        if (u == p)
            continue;

        if (color[u] == -1)
        {
            isTreeEdge[idx] = true;
            dfs(u, v, 1 - c, d + 1);
        }
    }
}

void buildLCA(int n)
{
    LOG_N = 0;
    while ((1 << LOG_N) <= n)
        LOG_N++;

    up.assign(n + 1, vector<int>(LOG_N, -1));

    for (int v = 1; v <= n; v++)
    {
        up[v][0] = parent[v];
    }

    for (int j = 1; j < LOG_N; j++)
    {
        for (int v = 1; v <= n; v++)
        {
            if (up[v][j - 1] != -1)
            {
                up[v][j] = up[up[v][j - 1]][j - 1];
            }
        }
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    int diff = depth[a] - depth[b];
    for (int i = 0; i < LOG_N; i++)
    {
        if ((diff >> i) & 1)
        {
            a = up[a][i];
        }
    }

    if (a == b)
        return a;

    for (int i = LOG_N - 1; i >= 0; i--)
    {
        if (up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

bool isOnPath(int x, int a, int b, int l)
{
    return (lca(x, a) == x && lca(x, b) == l) ||
           (lca(x, b) == x && lca(x, a) == l);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    color.assign(n + 1, -1);
    isTreeEdge.assign(m, false);
    edges.resize(m);
    parent.assign(n + 1, -1);
    depth.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            dfs(i, -1, 0, 0);
        }
    }

    buildLCA(n);

    vector<int> errorEdges, notErrorEdges;

    for (int i = 0; i < m; i++)
    {
        if (!isTreeEdge[i])
        {
            int u = edges[i].first;
            int v = edges[i].second;

            if (color[u] == color[v])
            {
                errorEdges.push_back(i);
            }
            else
            {
                notErrorEdges.push_back(i);
            }
        }
    }

    vector<int> result;

    if (errorEdges.size() == 0)
    {
        for (int i = 0; i < m; i++)
        {
            if (!isTreeEdge[i])
            {
                result.push_back(i + 1);
            }
        }
    }
    else if (errorEdges.size() == 1)
    {
        result.push_back(errorEdges[0] + 1);
    }

    for (int i = 0; i < m; i++)
    {
        if (isTreeEdge[i])
        {
            int u = edges[i].first;
            int v = edges[i].second;
            int l = lca(u, v);

            bool canRemove = true;
            bool hasErrorPath = false;

            for (int errIdx : errorEdges)
            {
                int eu = edges[errIdx].first;
                int ev = edges[errIdx].second;
                int el = lca(eu, ev);

                if (isOnPath(u, eu, ev, el) || isOnPath(v, eu, ev, el))
                {
                    hasErrorPath = true;
                    break;
                }
            }

            if (!hasErrorPath)
            {
                for (int errIdx : errorEdges)
                {
                    int eu = edges[errIdx].first;
                    int ev = edges[errIdx].second;
                    int el = lca(eu, ev);

                    if (isOnPath(u, eu, ev, el) || isOnPath(v, eu, ev, el))
                    {
                        canRemove = false;
                        break;
                    }
                }
            }
            else
            {
                for (int notErrIdx : notErrorEdges)
                {
                    int neu = edges[notErrIdx].first;
                    int nev = edges[notErrIdx].second;
                    int nel = lca(neu, nev);

                    if (isOnPath(u, neu, nev, nel) || isOnPath(v, neu, nev, nel))
                    {
                        canRemove = false;
                        break;
                    }
                }
            }

            if (canRemove)
            {
                result.push_back(i + 1);
            }
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++)
    {
        if (i > 0)
            cout << " ";
        cout << result[i];
    }
    if (result.size() > 0)
        cout << "\n";

    return 0;
}