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
    int N, M;
    cin >> N >> M;
    vector<int> mt[N + 2];
    for(int i = 1; i <= M; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        mt[temp1].push_back(temp2);
        mt[temp2].push_back(temp1);
    }
    
    int target;
    cin >> target;

    set<int> res;
    int oldsize = res.size();
    res.insert(target);
    while(oldsize != res.size()){
        oldsize = res.size();
        for(auto i : res){
            for(auto x : mt[i])
                res.insert(x);
        }
    }
    
    cout << oldsize << "\n";
    for(auto i : res)
        cout << i << " ";
    return 0;
}