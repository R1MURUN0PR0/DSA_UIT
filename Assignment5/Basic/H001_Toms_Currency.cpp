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
    int n;
    cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    cout << s.size() << '\n';
    for (int i : s){
        cout << i << " ";
    }
    return 0;
}