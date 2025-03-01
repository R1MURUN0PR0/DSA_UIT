#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>

using namespace std;

const int number_tests = 10;
const int testcase_size = 1000000;

void saveToFile(const vector<double> &arr, const string &filename)
{   
    ofstream file(filename);
    file << fixed << setprecision(6);
    for (double num : arr)
    {
        file << num << "\n";
    }
    file.close();
}

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(0.0, 2000000.0);

    // Tạo dãy 1 với tính chất tăng dần
    vector<vector<double>> arrays(number_tests + 1, vector<double>(testcase_size));
    for (int i = 0; i < testcase_size; i++)
    {
        arrays[0][i] = dist(gen);
    }
    sort(arrays[0].begin(), arrays[0].end());
    saveToFile(arrays[0], "C:\\Users\\cuong\\Dropbox\\DSA_UIT\\Sorting_Report\\testcase\\testcase1.txt");

    // Tạo dãy 2 với tính chất giảm dần
    for (int i = 0; i < testcase_size; i++) {
        arrays[1][i] = dist(gen);
    }
    sort(arrays[1].rbegin(), arrays[1].rend());
    saveToFile(arrays[1], "C:\\Users\\cuong\\Dropbox\\DSA_UIT\\Sorting_Report\\testcase\\testcase2.txt");

    // Tạo 8 dãy với thứ tự ngẫu nhiên
    for (int i = 3; i <= number_tests; i++)
    {
        for (int j = 0; j < testcase_size; j++)
        {
            arrays[i][j] = dist(gen);
        }
        saveToFile(arrays[i], "C:\\Users\\cuong\\Dropbox\\DSA_UIT\\Sorting_Report\\testcase\\testcase" + to_string(i) + ".txt");
    }
    cout << "Done" << endl;
    return 0;
}
