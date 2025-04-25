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

    int n;
    cin >> n;
    vector<int> v;
    while(n > 0){
        if(n % 2 == 1)
            v.push_back(1);

        if(n % 2 == 0)
            v.push_back(0);
        n /= 2;
    }
    for(int i = v.size() - 1; i >= 0; i--)
        cout << v[i];
    return 0;
}