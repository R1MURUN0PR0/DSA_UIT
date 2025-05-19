#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ull unsigned long long
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
    string s;
    cin >> s;
    stack<char> st;
    for (char c : s){
        if(!st.empty() && st.top() == c)
            st.pop();
        else st.push(c);
    }
    cout << st.size();
    return 0;
}