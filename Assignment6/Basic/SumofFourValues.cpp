#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ull unsigned long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r"))
    {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
    int N, X;
    cin >> N >> X;
    vector<int> v(N + 1);
    for(int i = 1; i <= N; i++)
        cin >> v[i];

    map <ull, pair<int, int>> mp;

    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            mp[(ull) v[i] + v[j]] = make_pair(i, j);

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++){
            if (mp.count(X - v[i] - v[j])) {
                pair<int, int> arr = mp[X - v[i] - v[j]];
                if (j < arr.fi) {
                    cout << i << ' ' << j << ' ' << arr.fi << ' ' << arr.se;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}