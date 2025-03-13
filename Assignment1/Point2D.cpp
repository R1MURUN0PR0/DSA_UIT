#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;

bool comp(pair<int, int> a, pair<int, int> b)
{
    // Nếu hoành độ khác nhau thì sắp cho nó tăng dần
    if (a.fi != b.fi)
        return a.fi < b.fi;
    // Nếu hoành độ bằng nhau thì sắp tung độ giảm dần
    return a.se > b.se;
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

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        v.push_back({temp1, temp2});
    }
    sort(v.begin(), v.end(), comp);
    for (auto i : v)
        cout << i.fi << " " << i.se << '\n';
    return 0;
}