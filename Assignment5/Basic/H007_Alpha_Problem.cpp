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
    ull a, x;
    cin >> a >> x;
    if(x == 10){
        cout << a;
        return 0;
    }
    vector<char> v;
    while(a != 0){
        short temp = a % x;
        v.push_back('0' + temp);
        a = a / x;
    }
    if(v.empty()) cout << 0;
    else{
        for(int i = v.size() - 1; i >= 0; i--)
            cout << v[i];
    }
    return 0;
}