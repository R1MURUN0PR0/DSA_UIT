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
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int a[n];
        for (int j = 0; j < n; j++)
            cin >> a[j];

        sort(a, a + n);
        // Nếu mảng chỉ có 2 phần tử thì ta đưa hết vào S1 vì nếu không thì TS = 0
        if (n == 2)
        {
            cout << a[1] - a[0] << "\n";
            continue;
        }
        // Nếu mảng có 3 phần tử thì ta đưa 2 số đầu cuối vào S1 để được tổng lớn nhất
        if (n == 3)
        {
            cout << a[2] - a[0] << "\n";
            continue;
        }
        // Nếu mảng có > 3 phần tử thì ta lấy trọng số bằng cách tính 2 lần hiệu của phần tử lớn nhất và nhỏ nhất
        cout << (a[n - 1] - a[0]) + (a[n - 2] - a[1]) << "\n";
    }
    return 0;
}