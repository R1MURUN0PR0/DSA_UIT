#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
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
    string Sb, Se;
    cin >> Sb >> Se;
    string s1, s2, res;
    int i;
    for (i = 0; i < Sb.size(); i++)
    {
        s1 = Sb.substr(i, Sb.size() - i);
        s2 = Se.substr(0, Sb.size() - i);
        if (s1 == s2)
            break;
    }
    res = Sb.substr(0, i) + Se;
    cout << res.size() << endl
         << res;
    return 0;
}