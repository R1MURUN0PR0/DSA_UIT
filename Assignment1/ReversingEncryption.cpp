#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
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
    const int n = s.size();
    vector<int> v;
    // Tìm các ước của n
    for (int i = 1; i <= sqrt(n); i++){
        if (i * i == n) v.push_back(i);
        else if (n % i == 0){
            v.push_back(i);
            v.push_back(n / i);
        }
    }
    sort(v.begin(), v.end());
    // Đảo ngược chuỗi con s[1...d] với thứ tự tăng dần từ 1 tới n
    for (int i : v){
        reverse(s.begin(), s.begin() + i);
    }
    cout << s;
    return 0;
}