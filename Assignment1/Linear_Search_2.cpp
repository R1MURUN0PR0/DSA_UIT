#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;

int LinearSearch(vector<int> &a, int start, int n, int k)
{
    for (int i = start; i < n; i++)
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
    vector<int> res;
    int temp = LinearSearch(a, 0, n, k);
    if (temp == -1)
    {
        cout << 0;
        exit(0);
    }
    res.push_back(temp);
    // Tìm tất cả các phần tử trùng còn lại bắt đầu từ vị trí trước
    while (res[res.size() - 1] != -1)
    {
        int next = LinearSearch(a, res[res.size() - 1] + 1, n, k);
        res.push_back(next);
    }
    cout << res.size() - 1 << endl;
    for (int i = 0; i < res.size() - 1; i++)
    {
        cout << res[i] << " " << res[i] + 1 << endl;
    }
}