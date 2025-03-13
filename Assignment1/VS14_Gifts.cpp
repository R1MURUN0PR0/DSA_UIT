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
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    int temp = 0, i = 0, j = v.size() - 1;
    // Kĩ thuật hai con trỏ giúp chỉ duyệt qua một lần mảng
    while (i < j)
    {
        int sum = v[i] + v[j];
        // Nếu tổng hai số nhỏ hơn hoặc bằng k, cập nhật temp và con trỏ đầu
        if (sum <= k)
        {
            temp = max(temp, sum);
            i++;
        }
        // Nếu không, cập nhật con trỏ cuối
        else j--;
    }
    cout << temp;
    return 0;
}