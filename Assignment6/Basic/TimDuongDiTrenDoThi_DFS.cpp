#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;

vector<int> v[N];

int d[N], past[N], n, m;

void solve(char x, char y) {
    // Reset the distance and past arrays
    // to ensure they are ready for the new DFS search
    int s = x - 'A';
    int u = y - 'A';
    fill_n(d, 27, -1);
    fill_n(past, 27, -1);

    
    stack<int> q;
    q.push(s);
    d[s] = 0;
    while (!q.empty()) {
        int x = q.top();
        q.pop();
        for (auto y : v[x])
            if (d[y] == -1) {
                d[y] = d[x] + 1;
                past[y] = x;
                q.push(y);
            }
    }

    if (d[u] == -1) {
        cout << "no_path\n";
        return;
    }

    stack<char> res;
    while (u != -1) {
        res.push(char('A' + u));
        u = past[u];
    }
    while (!res.empty()) {
        cout << res.top() << " ";
        res.pop();
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r"))
    {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
    cin >> n >> m;

    // pass the input of edges
    char x;
    for (int i = 1; i <= n; i++)
        cin >> x;
    
    // Read the edges and build the adjacency list
    for (int i = 1; i <= m; i++) {
        char x, y;
        cin >> x >> y;
        v[x - 'A'].push_back(y - 'A');
    }
    
    cin >> m;
    while (m--) {
        char x, y;
        cin >> x >> y;
        solve(x, y);
    }
    return 0;
}