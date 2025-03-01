#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

int partition(vector<double> &arr, int low, int high)
{
    int mid = (low + high) / 2;
    double pivot = arr[mid];
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

void QuickSort(vector<double> &arr, int low, int high)
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
    vector<double> arr;
    // Đọc file và lưu trữ vào mảng arr
    ifstream file("testcase1.txt");
    double num;
    while (file >> num)
        arr.push_back(num);

    file.close();
    // Bắt đầu tính giờ
    auto start = high_resolution_clock::now();

    QuickSort(arr, 0, arr.size() - 1);

    // Kết thúc tính giờ
    auto end = high_resolution_clock::now();

    double time_taken = duration<double, milli>(end - start).count();

    cout << "Execution time is " << time_taken << " ms" << endl;
    return 0;
}
