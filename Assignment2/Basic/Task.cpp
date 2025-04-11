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
    long long n, k, p, q;
    cin >> n >> k >> p >> q;
    // Biến thành số thứ tự của mảng 1 chiều
    long long alice = 2 * (p - 1) + q;
    long long bob = alice - k;
    // Ưu tiên bàn phía trước của Alice
    // Ta chỉ xét hai bàn cùng đề phía trước và phía sau
    if (bob >= 1)
    {
        long long pos = bob % 2;
        long long u = bob / 2;
        if (pos == 0)
            cout << u << " " << 2;
        else
            cout << u + 1 << " " << 1;
    }
    else
    {
        bob = alice + k;
        if (bob <= n)
        {
            long long pos = bob % 2;
            long long u = bob / 2;
            if (pos == 0)
                cout << u << " " << 2;
            else
                cout << u + 1 << " " << 1;
        }
        else
            cout << -1;
    }
    return 0;
}