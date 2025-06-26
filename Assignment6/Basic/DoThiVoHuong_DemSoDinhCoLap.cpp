#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r"))
    {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }

    int m, n;
    cin >> m >> n;
    vector<int> g[m];
    for(int i = 0; i < n; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        g[temp1].push_back(temp2);
        g[temp2].push_back(temp1);
    }
    
    int cnt = 0;
    for(int i = 0; i < m; i++){
        if(g[i].empty()) cnt++;
    }
      
    cout << cnt;
    return 0;
}