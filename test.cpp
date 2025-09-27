#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

struct linex {
    int v;
    int w;
    int nxt;
    int c;
};

struct Point {
    int x, y, tx, ty;
};

int head[210], cnt, cpos[210], vis[210], qvis[210], totc, dis[210], infinite = 1000000000;
linex l[21000];
queue<int> que;
int id[105][105];

void add(int u, int v, int w, int c) {
    l[cnt].nxt = head[u];
    head[u] = cnt;
    l[cnt].v = v;
    l[cnt].w = w;
    l[cnt].c = c;
    cnt++;
    l[cnt].nxt = head[v];
    head[v] = cnt;
    l[cnt].v = u;
    l[cnt].w = 0;
    l[cnt].c = -c;
    cnt++;
}

int spfa(int st, int en, int n) {
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
        dis[i] = infinite;
        cpos[i] = head[i];
    }
    que.push(st);
    dis[st] = 0;
    vis[st] = 1;
    qvis[st] = 1;
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        qvis[t] = 0;
        for (int j = head[t]; j != -1; j = l[j].nxt) {
            if (l[j].w > 0 && dis[l[j].v] > dis[t] + l[j].c) {
                dis[l[j].v] = dis[t] + l[j].c;
                vis[l[j].v] = 1;
                if (!qvis[l[j].v]) {
                    que.push(l[j].v);
                    qvis[l[j].v] = 1;
                }
            }
        }
    }
    return vis[en];
}

long long dfs(int p, int en, int curr) {
    if (p == en) return curr;
    int flow = 0;
    for (int j = cpos[p]; j != -1 && flow < curr; j = l[j].nxt) {
        cpos[p] = j;
        qvis[p] = 1;
        if (l[j].w > 0 && dis[l[j].v] == dis[p] + l[j].c && !qvis[l[j].v]) {
            int x = dfs(l[j].v, en, min(curr - flow, l[j].w));
            flow += x;
            l[j].w -= x;
            l[j ^ 1].w += x;
            totc += l[j].c * x;
        }
        qvis[p] = 0;
    }
    return flow;
}

vector<pair<int, int>> calculateAnswer(int n, vector<int>& arr1, vector<int>& arr2) {
    vector<int> ansv[2];
    vector<pair<int, int>> result;
    Point pc[105];
    int flow, flag;

    for (int i = 0; i < n * 2 + 2; i++) head[i] = -1;
    cnt = 0;
    totc = 0;
    flow = 0;

    for (int i = 0; i < n; i++) {
        add(n * 2, i, 1, 0);
        add(i + n, n * 2 + 1, 1, 0);
        for (int j = 0; j < n; j++) {
            id[i][j] = cnt;
            add(i, j + n, 1, abs(i - j) + abs(arr1[i] - arr2[j]));
        }
    }

    while (spfa(n * 2, n * 2 + 1, n * 2 + 2)) flow += dfs(n * 2, n * 2 + 1, infinite);

    for (int i = 0; i < n; i++) {
        pc[i].x = i;
        pc[i].y = arr1[i];
        for (int j = 0; j < n; j++) {
            if (l[id[i][j]].w == 0) {
                pc[i].tx = j;
                pc[i].ty = arr2[j];
            }
        }
    }

    while (true) {
        flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (pc[j].tx <= pc[i].x && pc[i].x < pc[j].x && pc[j].x <= pc[i].tx) {
                    ansv[0].push_back(pc[i].x);
                    ansv[1].push_back(pc[j].x);
                    swap(pc[i].x, pc[j].x);
                    flag = 1;
                }
            }
        }
        if (!flag) break;
    }

    while (true) {
        flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (pc[j].ty <= pc[i].y && pc[i].y < pc[j].y && pc[j].y <= pc[i].ty) {
                    ansv[0].push_back(pc[i].x);
                    ansv[1].push_back(pc[j].x);
                    swap(pc[i].y, pc[j].y);
                    flag = 1;
                }
            }
        }
        if (!flag) break;
    }

    for (int i = 0; i < ansv[0].size(); i++) {
        result.push_back({ansv[0][i] + 1, ansv[1][i] + 1});
    }

    return result;
}

void generatePermutation(vector<int>& arr, int n) {
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        int num;
        do {
            num = rnd.next(1, n);
        } while (visited[num - 1]);
        arr[i] = num;
        visited[num - 1] = true;
    }
}

void writeTest(int z) {
    string num = (z > 9) ? to_string(z) : "0" + to_string(z);
    fstream test;
    fstream answer;
    test.open("2Input" + num + ".txt", ios::app);
    answer.open("2Output" + num + ".txt", ios::app);
    int t = rnd.next(1, (int)pow(10, 4));
    test << t << endl;
    while (t--) {
        int n = rnd.next(2, 100);
        test << n << endl;

        vector<int> arr1(n), arr2(n);
        
        generatePermutation(arr1, n);
        generatePermutation(arr2, n);
        
        for (int i = 0; i < n; i++) {
            test << arr1[i] << (i == n - 1 ? "" : " ");
        }
        test << endl;

        for (int i = 0; i < n; i++) {
            test << arr2[i] << (i == n - 1 ? "" : " ");
        }
        test << endl;
        vector<pair<int, int>> ans = calculateAnswer(n, arr1, arr2);
        answer << ans.size() << endl;
    }
    answer.close();
    test.close();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    for (int no = 0; no < 3; no++)
        writeTest(no);
    return 0;
}