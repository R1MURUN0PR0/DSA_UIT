#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 6;

vector<int> getLIS(int N, vector<int>& arr) {
    vector<pair<int, int>> dp;  
    unordered_map<int, int> prv;
    
    // Process array in reverse order
    for (int ix = N - 1; ix >= 0; --ix) {
        int ve = -arr[ix];
        
        // Binary search to find insertion point
        auto it = lower_bound(dp.begin(), dp.end(), make_pair(ve, 0),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first < b.first;
             });
        
        int tmp = -1;  // Default previous index
        int i = distance(dp.begin(), it);
        
        if (i == dp.size()) {
            if (!dp.empty()) {
                tmp = dp.back().second;
            }
            dp.emplace_back(ve, ix);
        } else {
            if (i > 0) {
                tmp = dp[i-1].second;
            }
            dp[i] = {ve, ix};
        }
        prv[ix] = tmp;
    }
    
    // Reconstruct the LIS
    vector<int> res;
    int cur = dp.back().second;
    while (cur >= 0) {
        res.push_back(arr[cur]);
        cur = prv[cur];
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r"))
    {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> lis = getLIS(arr.size(), arr);
    cout << lis.size() << "\n";
    for (int num : lis) {
        cout << num << " ";
    }
    return 0;
}