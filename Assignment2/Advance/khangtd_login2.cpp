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
    int n, k;
    cin >> n >> k;
    map<string, vector<string>> mp;
    for(int i = 0; i < n; i++){
        string s1, s2;
        cin >> s1 >> s2;
        mp[s1].push_back(s2);
    }
    for(int i = 0; i < k; i++){
        string temp;
        cin >> temp;
        if(mp.find(temp)!= mp.end()){
            for(string i : mp[temp]){
                cout << i << " ";
            }
            cout << "\n";
        }
        else cout << "Chua Dang Ky!" << "\n";
    }
    return 0;
}