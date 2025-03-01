#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

void Heapify(vector<double> &arr, int n, int i)
{
    // Coi i là lớn nhất và là gốc
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // Nếu nút con trái lớn hơn gốc
    if (left < n && arr[left] > arr[largest])
        largest = left;
    // Nếu nút con phải lớn hơn gốc
    if (right < n && arr[right] > arr[largest])
        largest = right;
    // Nếu số lớn nhất không phải là gốc
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // Tiếp tục đệ quy với cây con
        Heapify(arr, n, largest);
    }
}

void HeapSort(vector<double> &arr, int n)
{
    // Xây dựng Max-Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);
    // Trích xuất từng phần tử từ Heap
    for (int i = n - 1; i > 0; i--)
    {
        // Đưa gốc về cuối
        swap(arr[0], arr[i]);
        // Heapify lại gốc
        Heapify(arr, i, 0);
    }
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
    // Bắt đầu tính giờ
    auto start = high_resolution_clock::now();

    HeapSort(arr, arr.size() - 1);

    // Kết thúc tính giờ
    auto end = high_resolution_clock::now();

    double time_taken = duration<double, milli>(end - start).count();

    cout << "Execution time is " << time_taken << " ms" << endl;
    return 0;
}