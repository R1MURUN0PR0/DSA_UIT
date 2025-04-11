#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

int a[N];
bool b[N];
pair<int, int> p[N];
vector<int> G[N];

int DFS(int u)
{
    b[u] = true;
    for (auto v : G[u])
    {
        if (b[v])
            continue;
        return DFS(v) + 1;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r"))
    {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], p[i] = {a[i], i};

    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++)
        G[i].push_back(p[i].second);
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i])
            continue;
        res += DFS(i) - 1;
    }

    sort(p + 1, p + 1 + n, greater<pair<int, int>>());
    for (int i = 1; i <= n; i++)
        G[i].clear(), b[i] = false;
    for (int i = 1; i <= n; i++)
        G[i].push_back(p[i].second);
    int res2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i])
            continue;
        res2 += DFS(i) - 1;
    }

    cout << min(res, res2);
    return 0;
}