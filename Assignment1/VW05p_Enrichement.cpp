#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;

// Hàm tính tổng các số trong ma trận 3x3 ô
int sum_matrix(vector<vector<int>> &a, int n, int m)
{
    int sum = 0;
    for (int k = n; k < n + 3; k++)
    {
        for (int l = m; l < m + 3; l++)
            sum += a[k][l];
    }
    return sum;
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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    // Tính tất cả tổng các ma trận 3x3 ô
    vector<int> res;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < m - 2; j++)
        {
            res.push_back(sum_matrix(a, i, j));
        }
    }
    // Sắp xếp và in kết quả
    sort(res.begin(), res.end());
    cout << res[0];
    return 0;
}