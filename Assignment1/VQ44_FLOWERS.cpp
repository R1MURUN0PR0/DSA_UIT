#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;

int main(){
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
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    // Sắp xếp mảng theo thứ tự tăng dần
    sort(a.begin(), a.end());

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
    while (res.size() < k){
        if (after[temp2] != 0){
            res.push_back(after[temp2]);
            after[temp2] = 0;
        }
        temp2++;
    }

    for (int j : res)
        cout << j << " ";
}