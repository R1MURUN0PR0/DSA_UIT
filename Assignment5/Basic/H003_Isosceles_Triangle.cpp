#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 9;

ll nC2(int n)
{
    return (n < 2) ? 0 : (ll)n * (n - 1) / 2;
}

ll nC3(int n)
{
    return (n < 3) ? 0 : (ll)n * (n - 1) * (n - 2) / 6;
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
    int t;
    cin >> t;
    map<int, pair<int, int>> freq;
    int max_val = 0;
    for (int i = 0; i < t; ++i)
    {
        int x;
        cin >> x;
        freq[x].first++;
    }

    for (auto x = freq.begin(); x != freq.end(); x++)
    {
        if (x == freq.begin())
        {
            x->second.second = x->second.first;
            continue;
        }
        auto y = x;
        y--;
        x->second.second = y->second.second + x->second.first;
    }

    ll sum = 0;
    for (auto &x : freq)
    {
        auto it = freq.lower_bound(x.first * 2);
        it--;
        sum += nC2(x.second.first) * (it->second.second - x.second.first) + nC3(x.second.first);
    }

    cout << sum;
    return 0;
}