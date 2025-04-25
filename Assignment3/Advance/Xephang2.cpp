#include <bits/stdc++.h>
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

    // Lập danh sách từ 1 tới n và trỏ vị trí
    for (int i = 1; i <= n; ++i) {
        call.push_back(i);
        pos[i] = prev(call.end());
    }

    // Đặt lại vị trí cùng con trỏ nó sau đó in ra phần tử cuối
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;

        if (pos.count(x)) {
            call.erase(pos[x]);
        }
        call.push_front(x);
        pos[x] = call.begin();
        cout << call.back() << " ";
    }

    return 0;
}