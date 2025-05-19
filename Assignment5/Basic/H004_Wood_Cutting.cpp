#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ull unsigned long long
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;


ull minCutCost(vector<int>& v) {
    priority_queue<ull, vector<ull>, greater<ull>> pq(v.begin(), v.end());
    
    ull totalCost = 0;
    while (pq.size() > 1) {
        ull fi = pq.top();
        pq.pop();
        ull se = pq.top();
        pq.pop();

        ull cost = fi + se;
        totalCost += cost;
        pq.push(cost);
    }

    return totalCost;
}

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
    ull S;
    cin >> n >> S;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << minCutCost(v);
    return 0;
}