#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;

int partition(vector<string> &arr, int low, int high)
{
    string pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (true)
    {

        // Tìm phần tử bên trái ngoài cùng của dãy
        // mà lớn hơn hoặc bằng pivot
        do
        {
            i++;
        } while (arr[i] < pivot);

        // Tìm phần tử bên phải ngoài cùng của dãy
        // mà bé hơn hoặc bằng pivot
        do
        {
            j--;
        } while (arr[j] > pivot);

        /// Nếu hai phần tử đó gặp nhau
        if (i >= j)
            return j;

        // Nếu không thì sắp xếp cho đúng
        swap(arr[i], arr[j]);
    }
}

void QuickSort(vector<string> &arr, int low, int high)
{

    if (low < high)
    {
        // pi là chỉ số pivot trước đã được
        // đặt ở đúng vị trí
        int pi = partition(arr, low, high);

        // Độc lập thực hiện sắp xếp cho hai phần
        // trái và phải của pivot như vậy
        QuickSort(arr, low, pi);
        QuickSort(arr, pi + 1, high);
    }
}

int partition(vector<pair<string, int>> &arr, int low, int high, bool (*comp)(pair<string, int>, pair<string, int>))
{
    pair<string, int> pivot = arr[low];
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

void QuickSort(vector<pair<string, int>> &arr, int low, int high, bool (*comp)(pair<string, int>, pair<string, int>))
{
    if (low < high)
    {
        int pi = partition(arr, low, high, comp);
        QuickSort(arr, low, pi, comp);
        QuickSort(arr, pi + 1, high, comp);
    }
}

bool comp(pair<string, int> a, pair<string, int> b)
{
    if (a.se != b.se)
        return a.se > b.se;

    string sa = a.fi, sb = b.fi;
    sa.erase(0, sa.find_first_not_of('0'));
    sb.erase(0, sb.find_first_not_of('0'));
    if (sa.empty())
        sa = "0";
    if (sb.empty())
        sb = "0";
    if (sa.size() != sb.size())
        return sa.size() < sb.size();
    return sa < sb;
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
    int t;
    cin >> t;
    vector<string> a(t);
    vector<pair<string, int>> b;

    for (int i = 0; i < t; i++)
    {
        cin >> a[i];
    }
    QuickSort(a, 0, t - 1);
    int c = 1;
    for (int i = 0; i < t - 1; i++)
    {
        if (a[i] != a[i + 1])
        {
            b.push_back({a[i], c});
            c = 1;
            continue;
        }
        else
        {
            c++;
        }
    }
    b.push_back({a[t - 1], c});
    QuickSort(b, 0, b.size() - 1, comp);
    for (auto &p : b)
    {
        cout << p.fi << " " << p.se << "\n";
    }
    return 0;
}