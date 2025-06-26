#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

// Function to find the maximum profit
ull knapsack(int W, vector<int> &val, vector<int> &wt) {

    // Initializing dp vector
    vector<ull> dp(W + 1, 0);

    // Taking first i elements
    for (int i = 1; i <= wt.size(); i++) {
        
        // Starting from back, so that we also have data of
        // previous computation of i-1 items
        for (int j = W; j >= wt[i - 1]; j--) {
            dp[j] = max(dp[j], dp[j - wt[i - 1]] + (ull) val[i - 1]);
        }
    }
    return dp[W];
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
    int n, W;
    cin >> n >> W;
    vector<int> wt(n), val(n);
    for(int i = 0; i < n; i++){
        cin >> wt[i] >> val[i];
    }
    cout << knapsack(W, val, wt) << "\n";
    return 0;
}