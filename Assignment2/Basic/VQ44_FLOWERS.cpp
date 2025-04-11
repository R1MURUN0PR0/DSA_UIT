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
    int n, k;
    cin >> n >> k;
    vector<int> a, res;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    // Sắp xếp mảng theo thứ tự tăng dần
    QuickSort(a, 0, n - 1);

    // Khai báo vector after để đánh dấu biến đã đưa vào res
    vector<int> after = a;

    // Duyệt từ đầu tới cuối vector a để chọn các phần tử khác nhau
    res.push_back(a[0]);

    after[0] = 0;
    int temp1 = 0, temp2 = 0;
    for (int i = 1; i < n; i++)
    {
        if (res[temp1] != a[i] && res.size() < k)
        {
            res.push_back(a[i]);
            after[i] = 0;
            temp1++;
        }
    }

    // Chọn phần tử có vị trí đầu tiên của vector after
    // chưa xuất hiện đến khi mảng res đủ
    while (res.size() < k)
    {
        if (after[temp2] != 0)
        {
            res.push_back(after[temp2]);
            after[temp2] = 0;
        }
        temp2++;
    }

    for (int j : res)
        cout << j << " ";
}