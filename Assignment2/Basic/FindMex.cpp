#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
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

void QuickSort(vector<int> &arr, int low, int high)
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
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    QuickSort(a, 0, n - 1);
    // Tìm giá trị MEX của dãy sắp xếp
    int mex = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == mex)
            mex++;
    }
    cout << mex;
    return 0;
}