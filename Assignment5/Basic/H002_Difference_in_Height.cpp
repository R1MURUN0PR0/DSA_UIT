#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ull unsigned long long
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;

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
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ull sum = 0;
    for (int i = 0; i < n; i++){
        sum += 1LL * (2 * i - n + 1) * v[i];
    }
    cout << sum;
    return 0;
}