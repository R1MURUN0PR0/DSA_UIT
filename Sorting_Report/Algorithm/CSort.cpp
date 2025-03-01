#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

int main()
{
    vector<double> arr;
    // Đọc file và lưu trữ vào mảng arr
    ifstream file("testcase1.txt" );
    double num;
    while (file >> num)
        arr.push_back(num);

    file.close();
    // Bắt đầu tính giờ
    auto start = high_resolution_clock::now();

    sort(arr.begin(), arr.end());

    // Kết thúc tính giờ
    auto end = high_resolution_clock::now();

    double time_taken = duration<double, milli>(end - start).count();

    cout << "Execution time is " << time_taken << " ms" << endl;
    return 0;
}
