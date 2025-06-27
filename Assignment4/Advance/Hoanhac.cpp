#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")) {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++)
        cin >> v[i];

    stack<pair<int, int>> st;
    long long res = 0;

    for (int cur : v) {
        int cnt = 1;

        while (!st.empty() && st.top().fi < cur) {
            res += st.top().se;
            st.pop();
        }

        if (!st.empty() && st.top().fi == cur) {
            int freq = st.top().se;
            res += freq;
            cnt = freq + 1;
            st.pop();
        }

        if (!st.empty()) res++;

        st.emplace(cur, cnt);
    }

    cout << res;
    return 0;
}
