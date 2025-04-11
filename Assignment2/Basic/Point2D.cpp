#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;

int partition(vector<pair<int, int>> &arr, int low, int high, bool (*comp)(pair<int, int>, pair<int, int>))
{
    pair<int, int> pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (true)
    {
        do
        {
            i++;
        } while (comp(arr[i], pivot));

        do
        {
            j--;
        } while (comp(pivot, arr[j]));

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

void QuickSort(vector<pair<int, int>> &arr, int low, int high, bool (*comp)(pair<int, int>, pair<int, int>))
{
    if (low < high)
    {
        int pi = partition(arr, low, high, comp);
        QuickSort(arr, low, pi, comp);
        QuickSort(arr, pi + 1, high, comp);
    }
}

bool comp(pair<int, int> a, pair<int, int> b)
{
    // Nếu hoành độ khác nhau thì sắp cho nó tăng dần
    if (a.fi != b.fi)
        return a.fi < b.fi;
    // Nếu hoành độ bằng nhau thì sắp tung độ giảm dần
    return a.se > b.se;
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
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        v.push_back({temp1, temp2});
    }
    QuickSort(v, 0, n - 1, comp);
    for (auto i : v)
        cout << i.fi << " " << i.se << '\n';
    return 0;
}