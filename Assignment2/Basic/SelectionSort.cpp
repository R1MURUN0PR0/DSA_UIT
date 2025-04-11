#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;

void SelectionSort(int arr[], int n)
{
    // Xét từng vị trí trong mảng
    for (int i = 0; i < n - 1; i++)
    {
        int pos = i;
        /* Tìm phần tử nhỏ nhất
        từ vị trí i tới n */
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[pos])
                pos = j;
        }
        /* Đưa phần tử thứ i
        về đúng vị trí */
        if (pos != i) {  // Chỉ swap khi cần
            swap(arr[i], arr[pos]);
            for (int k = 0; k < n; k++) {
                cout << arr[k] << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r"))
    {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    SelectionSort(arr, n);
    return 0;
}