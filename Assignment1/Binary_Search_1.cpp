#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;

// Hàm vừa tìm số nguyên vừa đếm số lần duyệt
pair<int, int> binary_search(vector<int> a, int n, int k)
{
    int left = 0, right = n - 1, count = 0;
    while (left <= right)
    {
        // Biến đếm để in số lần duyệt
        count++;
        int mid = (left + right) / 2;
        if (a[mid] == k)
            return {mid, count};
        else if (a[mid] < k)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return {-1, 0};
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

    pair<int, int> res = binary_search(a, n, k);
    if (res.fi == -1)
        cout << -1 << endl;
    else
        cout << res.fi << endl
             << res.se << endl;
}