#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int k = arr[i];
        int j = i - 1;
        /* Chuyển các phần tử lớn hơn
        phần tử đang xét sang phải
        1 vị trí so với vị trí hiện tại */
        while (j >= 0 && arr[j] > k)
        {
            arr[j + 1] = arr[j];
            j--;
            for(int l = 0; l < n; l++){
                cout << arr[l] << " ";
            }
            cout << "\n";
        }
        /* Chèn phần tử đang xét
        vào vị trí đúng */
        arr[j + 1] = k;
        for(int t = 0; t < n; t++){
            cout << arr[t] << " ";
        }
        cout << "\n";
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
    InsertionSort(arr, n);
    
    return 0;
}