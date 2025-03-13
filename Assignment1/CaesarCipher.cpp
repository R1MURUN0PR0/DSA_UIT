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
    int k;
    string s;
    cin >> k;
    // Bỏ qua '\n'
    cin.ignore();
    // Lấy cả dấu cách
    getline(cin, s);
    for (int i = 0; i < s.length(); i++){
        // Khi gặp dấu cách, in ra khoảng trắng rồi bỏ qua
        if (s[i] == ' '){
            cout << " ";
            continue;
        }
        // Dùng thuật E(x)=(x+k) mod 26
        s[i] = (s[i] - 'A' + k) % 26 + 'A';
        cout << s[i];
    }
}