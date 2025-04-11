#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;

void BubbleSort(vector<int> &arr)
{
    int n = arr.size();
    // Xét tất cả các cặp liền kề trong mảng

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // Sắp xếp các cặp này
            if (arr[j] > arr[j + 1])    
            {
                swap(arr[j], arr[j + 1]);
                for(int k = 0; k < n; k++){
                    cout << arr[k] << " ";
                }
                cout << "\n";
            }
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
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    BubbleSort(arr);
    return 0;
}