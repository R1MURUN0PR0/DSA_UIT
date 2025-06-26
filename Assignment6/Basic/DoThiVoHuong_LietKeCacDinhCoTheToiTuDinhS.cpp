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
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        g[tmp1].push_back(tmp2);
        g[tmp2].push_back(tmp1);
    }

    if(g[0].empty()) cout << "KHONG";
    else{
        set<int> s;
        for(auto i : g[0])
            s.insert(i);
        int oldsize = -1;
        while(oldsize != s.size()){
            oldsize = s.size();
            for(auto i : s){
                for(auto x : g[i])
                    s.insert(x);
            }
        }
        s.erase(0);
        for(auto i : s)
            cout << i << " ";
    }
    return 0;
}