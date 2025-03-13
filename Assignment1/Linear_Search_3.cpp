#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;

vector<int> LinearSearchMEX(vector<int> &a, int n)
{
    vector<int> res;
    bool b[N];
    int MEX = 0;
    for (int i = 0; i < n; i++)
    {
        // Lập một mảng ánh xạ với phần tử đã qua
        b[a[i]] = true;
        while (b[MEX])
        {
            // Tìm MEX nhỏ nhất mà không trùng với phần tử trước
            MEX++;
        }
        res.push_back(MEX);
    }
    return res;
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
    int n;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    vector<int> res = LinearSearchMEX(a, n);
    for (int i : res)
    {
        cout << i << " ";
    }
}