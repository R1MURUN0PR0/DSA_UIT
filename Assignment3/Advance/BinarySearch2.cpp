#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

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
    if (a.fi != b.fi)
        return a.fi < b.fi;
    return a.se < b.se;

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

    int N, Q;
    cin >> N >> Q;
    vector<pair<int, int>> v;
    for(int i = 1; i <= N; i++){
        int temp;
        cin >> temp;
        v.push_back({temp, i});
    }
    QuickSort(v, 0, v.size() - 1, comp);
    for (int i = 0; i < Q; ++i) {
        int x, y;
        string type;
        cin >> type >> x >> y;

        auto lower_it = lower_bound(v.begin(), v.end(), make_pair(y, 0));
        auto upper_it = upper_bound(v.begin(), v.end(), make_pair(y, N + 1));

        if (lower_it == v.end() || lower_it->first != y)
            cout << -1 << "\n";
        else {
            if (x == 1)
                cout << lower_it->second << "\n";
            else if (x == 2)
                cout << (upper_it - 1)->second << "\n";
        }
    }
    return 0;
}