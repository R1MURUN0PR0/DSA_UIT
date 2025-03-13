#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;

int LinearSearch(vector<int> &a, int n, int k)
{
    // Duyệt từ đầu tới cuối mảng để tìm phần tử
    for (int i = 0; i < n; i++)
    {
        if (a[i] == k)
            return i;
    }
    return -1;
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
    int n, k;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    cin >> k;

    int res = LinearSearch(a, n, k);
    if (res == -1)
        cout << res;
    else
    {
        cout << res << endl;
        cout << res + 1 << endl;
        cout << n - 1 - res << endl;
        cout << n - res << endl;
    }
}