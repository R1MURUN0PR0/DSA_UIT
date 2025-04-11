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
    string s, t;
    cin >> s >> t;
    int m = s.size(), n = t.size();
    if(n > m){
        cout << "NO";
        return 0;
    }
    vector<int> pos;
    for(int i = 0; i <= m - n; i++){
        if(s.substr(i, n) == t) pos.push_back(i);
    }
    if(pos.size() == 0){
        cout << "NO";
    }
    else{
        cout << "YES\n";
        for(int i : pos) cout << i + 1 << " ";
    }
    return 0;
}