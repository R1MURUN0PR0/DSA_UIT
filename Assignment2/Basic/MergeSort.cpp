#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> left_part(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> right_part(arr.begin() + mid + 1, arr.begin() + right + 1);
    
    int i = 0, j = 0, k = left;
    while (i < left_part.size() && j < right_part.size()) {
        if (left_part[i] <= right_part[j]) {
            arr[k++] = left_part[i++];
        } else {
            arr[k++] = right_part[j++];
        }
    }
    while (i < left_part.size()) {
        arr[k++] = left_part[i++];

    }
    while (j < right_part.size()) {
        arr[k++] = right_part[j++];
    }
    
    // Định dạng chuẩn để in ra
    for(int i = 0; i < arr.size(); i++){
        if(i == left && i == 0) cout << "[ " << arr[i];
        else if(i == 0) cout << arr[i];
        else if(i == left) cout << " [ " << arr[i];
        else if(i == arr.size() - 1 && i == right) cout << " " << arr[i] << " ]\n";
        else if(i == right) cout << " " << arr[i] << " ]";
        else if(i == arr.size() - 1) cout << " " << arr[i] << "\n";
        else cout << " " << arr[i];
    }
}

void merge_sort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    merge_sort(A, 0, N - 1);
    return 0;
}