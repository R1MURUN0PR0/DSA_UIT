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
    bool visited[m];
    fill_n(visited, m, false);
    for(int i = 0; i < n; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        g[temp1].push_back(temp2);
        g[temp2].push_back(temp1);
    }
    
    int cnt = 0;
    for(int i = 0; i < m; i++){
        if(!visited[i]){
            cnt++;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                int top = q.front();
                q.pop();
                for(auto x : g[top]){
                    if(!visited[x]){
                        q.push(x);
                        visited[x] = true;
                    }
                }
            }
        }
    }
    
    cout << cnt;
    return 0;
}