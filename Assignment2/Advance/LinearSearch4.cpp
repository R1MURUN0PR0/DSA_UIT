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
    int t;
    cin >> t;
    while (t--){
        int n, k, count = 0;
        cin >> n >> k;
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            mp[temp]++;
            if(mp[temp] == 2) count++;
        }
        int m = mp.size();
        if(m < k || m > 2*k) cout << "NO\n";
        else{
            if(m + count >= 2*k) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}