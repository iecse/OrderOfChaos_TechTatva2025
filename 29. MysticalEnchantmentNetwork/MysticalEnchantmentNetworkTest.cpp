#include "../testlib.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct Solver
{
    int n, m, LOG_N;
    vector<vector<pair<int, int>>> adj;
    vector<pair<int, int>> edges;

    vector<int> color, parent_, depth_;
    vector<bool> isTreeEdge;
    vector<vector<int>> up;

    Solver(int n, int m) : n(n), m(m)
    {
        adj.assign(n + 1, {});
        edges.resize(m);
        color.assign(n + 1, -1);
        isTreeEdge.assign(m, false);
        parent_.assign(n + 1, -1);
        depth_.assign(n + 1, 0);
    }

    void add_edge(int idx, int u, int v)
    {
        edges[idx] = {u, v};
        adj[u].push_back({v, idx});
        adj[v].push_back({u, idx});
    }

    void dfs(int v, int p, int c, int d)
    {
        color[v] = c;
        parent_[v] = p;
        depth_[v] = d;

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

    void buildLCA()
    {
        LOG_N = 0;
        while ((1 << LOG_N) <= n)
            LOG_N++;

        up.assign(n + 1, vector<int>(LOG_N, -1));
        for (int v = 1; v <= n; v++)
            up[v][0] = parent_[v];

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
        if (depth_[a] < depth_[b])
            swap(a, b);
        int diff = depth_[a] - depth_[b];

        for (int i = 0; i < LOG_N; i++)
        {
            if ((diff >> i) & 1)
                a = up[a][i];
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

    vector<int> solve()
    {
        // Build DFS forest and colors
        for (int i = 1; i <= n; i++)
        {
            if (color[i] == -1)
                dfs(i, -1, 0, 0);
        }

        buildLCA();

        vector<int> errorEdges, notErrorEdges;

        // Classify non-tree edges
        for (int i = 0; i < m; i++)
        {
            if (!isTreeEdge[i])
            {
                int u = edges[i].first;
                int v = edges[i].second;
                if (color[u] == color[v])
                    errorEdges.push_back(i);
                else
                    notErrorEdges.push_back(i);
            }
        }

        vector<int> result;

        // Same logic as your original code:
        if (errorEdges.size() == 0)
        {
            for (int i = 0; i < m; i++)
            {
                if (!isTreeEdge[i])
                    result.push_back(i + 1);
            }
        }
        else if (errorEdges.size() == 1)
        {
            result.push_back(errorEdges[0] + 1);
        }

        // Check tree edges
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
                    result.push_back(i + 1);
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};

// Generate a random connected graph
vector<pair<int, int>> generateConnectedGraph(int n, int m)
{
    vector<pair<int, int>> edges;
    vector<bool> connected(n + 1, false);

    // First create a random spanning tree to ensure connectivity
    vector<int> vertices;
    for (int i = 1; i <= n; i++)
    {
        vertices.push_back(i);
    }
    shuffle(vertices.begin(), vertices.end());

    connected[vertices[0]] = true;
    for (int i = 1; i < n; i++)
    {
        int u = vertices[i];
        int v = vertices[rnd.next(0, i - 1)];
        edges.push_back({u, v});
        connected[u] = true;
    }

    // Add remaining random edges
    while (edges.size() < m)
    {
        int u = rnd.next(1, n);
        int v = rnd.next(1, n);
        if (u == v)
            continue;
        if (u > v)
            swap(u, v);

        bool exists = false;
        for (auto &e : edges)
        {
            int x = e.first, y = e.second;
            if (x > y)
                swap(x, y);
            if (x == u && y == v)
            {
                exists = true;
                break;
            }
        }
        if (!exists)
        {
            edges.push_back({u, v});
        }
    }

    return edges;
}

// Generate a cycle graph
vector<pair<int, int>> generateCycle(int n)
{
    vector<pair<int, int>> edges;
    for (int i = 1; i < n; i++)
    {
        edges.push_back({i, i + 1});
    }
    edges.push_back({n, 1});
    return edges;
}

// Generate a bipartite graph
vector<pair<int, int>> generateBipartiteGraph(int n, int m)
{
    vector<pair<int, int>> edges;
    int n1 = rnd.next(1, n - 1);
    int n2 = n - n1;

    while (edges.size() < m)
    {
        int u = rnd.next(1, n1);
        int v = rnd.next(n1 + 1, n);

        bool exists = false;
        for (auto &e : edges)
        {
            if ((e.first == u && e.second == v) || (e.first == v && e.second == u))
            {
                exists = true;
                break;
            }
        }
        if (!exists)
        {
            edges.push_back({u, v});
        }
    }

    return edges;
}

void writeTest(int z)
{
    string inputFile = "Input" + (z > 9 ? to_string(z) : "0" + to_string(z)) + ".txt";
    string outputFile = "Output" + (z > 9 ? to_string(z) : "0" + to_string(z)) + ".txt";

    ofstream input(inputFile);
    ofstream output(outputFile);

    int n, m;
    vector<pair<int, int>> edges;

    if (z == 0)
    {
        // Test case 0: Small bipartite graph (should allow removing any non-tree edge)
        n = 4;
        m = 4;
        edges = {{1, 2}, {1, 3}, {2, 4}, {3, 4}};
    }
    else if (z == 1)
    {
        // Test case 1: Odd cycle + chord (only chord can be removed)
        n = 5;
        m = 6;
        edges = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 1}, {1, 3}};
    }
    else if (z == 2)
    {
        // Test case 2: Larger mixed case
        n = rnd.next(50, 100);
        m = min(rnd.next(n, 2 * n), n * (n - 1) / 2);

        // Start with a bipartite graph
        edges = generateBipartiteGraph(n, min(m - 2, n * n / 4));

        // Add a few edges to make it non-bipartite
        while (edges.size() < m)
        {
            int u = rnd.next(1, n);
            int v = rnd.next(1, n);
            if (u == v)
                continue;
            if (u > v)
                swap(u, v);

            bool exists = false;
            for (auto &e : edges)
            {
                int x = e.first, y = e.second;
                if (x > y)
                    swap(x, y);
                if (x == u && y == v)
                {
                    exists = true;
                    break;
                }
            }
            if (!exists)
            {
                edges.push_back({u, v});
            }
        }
    }

    // Write input
    input << n << " " << m << "\n";
    for (auto &edge : edges)
    {
        input << edge.first << " " << edge.second << "\n";
    }
    input.close();

    // Generate output using solver
    Solver solver(n, m);
    for (int i = 0; i < m; i++)
    {
        solver.add_edge(i, edges[i].first, edges[i].second);
    }

    vector<int> result = solver.solve();

    output << result.size() << "\n";
    for (int i = 0; i < (int)result.size(); i++)
    {
        if (i > 0)
            output << " ";
        output << result[i];
    }
    if (!result.empty())
        output << "\n";
    output.close();
}

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    for (int no = 0; no < 3; no++)
        writeTest(no);
    return 0;
}