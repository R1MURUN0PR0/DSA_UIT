#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

void merge(vector<double> &arr, vector<double> &temp, int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;
    // Sắp xếp hai mảng con vào mảng temp
    while (i <= mid && j <= right)
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    // Sao chép mảng temp vào arr
    for (int p = left; p <= right; p++)
        arr[p] = temp[p];
}

void MergeSort(vector<double> &arr, vector<double> &temp, int left, int right)
{
    if (left >= right)
        return;
    // Đệ quy sắp xếp hai mảng con
    int mid = (left + right) / 2;
    MergeSort(arr, temp, left, mid);
    MergeSort(arr, temp, mid + 1, right);
    merge(arr, temp, left, mid, right);
}
int main()
{
    vector<double> arr;
    // Đọc file và lưu trữ vào mảng arr
    ifstream file("C:\\Users\\cuong\\Dropbox\\DSA_UIT\\Sorting_Report\\testcase\\testcase1.txt");
    double num;
    while (file >> num)
        arr.push_back(num);

    file.close();

    // Tạo mảng tạm để giảm cấp phát động
    vector<double> temp(arr.size());

    // Bắt đầu tính giờ
    auto start = high_resolution_clock::now();

    MergeSort(arr, temp, 0, arr.size() - 1);

    // Kết thúc tính giờ
    auto end = high_resolution_clock::now();

    double time_taken = duration<double, milli>(end - start).count();

    cout << "Execution time is " << time_taken << " ms";
    return 0;
}