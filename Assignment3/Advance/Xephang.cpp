#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")) {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
    int n, m;
    cin >> n >> m;

    list<int> call;
    unordered_map<int, list<int>::iterator> pos;
    unordered_set<int> seen;

    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;

        if (pos.count(temp)) {
            call.erase(pos[temp]);
        }
        call.push_front(temp);
        pos[temp] = call.begin();
        seen.insert(temp);
    }

    for (int x : call) {
        cout << x << " ";
    }

    for (int i = 1; i <= n; i++) {
        if (seen.find(i) == seen.end()) {
            cout << i << " ";
        }
    }

    return 0;
}