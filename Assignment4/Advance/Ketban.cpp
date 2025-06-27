#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")) {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }

    int n, m;
    cin >> n >> m;
    vector<int> next(n + 1), prev(n + 1); 

    for (int i = 1; i <= n; i++){
        next[i] = i % n + 1;
        prev[i % n + 1] = i;
    }

    for (int i = 0; i < m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        // pos around tmp1
        prev[next[tmp1]] = prev[tmp1];
        next[prev[tmp1]] = next[tmp1];
        
        // pos between nexttmp2 and tmp1
        next[tmp1] = next[tmp2];
        prev[next[tmp2]] = tmp1;

        // pos between nexttmp2 and tmp1
        prev[tmp1] = tmp2;
        next[tmp2] = tmp1;
    }

    int cur = 1;
    do{
        cout << cur << " ";
        cur = next[cur];
    } while(cur != 1);

    return 0;
}
