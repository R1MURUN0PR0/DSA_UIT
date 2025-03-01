#include <bits/stdc++.h>
using namespace std;

void InterchangeSort(vector<int> &arr)
{
    int n = arr.size();
    // Xét tất cả các cặp trong mảng
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            // Triệt tiêu các cặp nghịch thế
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
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

void QuickSort(vector<int> &arr, int low, int high)
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
            }
        }
    }
}

void ShakeSort(vector<int> &arr)
{
    int n = arr.size();
    int l = 0;
    int r = n - 1;
    int k = n - 1;
    while (l < r)
    {
        // Duyệt mảng từ trái sang phải
        for (int i = l; i < r; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                int k = i;
            }
        }
        // Thiết lập cận phải mới
        r = k;
        // Duyệt mảng từ phải sang trái
        for (int i = r; i > l; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);
                int k = i;
            }
        }
        // Thiết lập cận trái mới
        l = k;
    }
}

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
        }
        /* Chèn phần tử đang xét
        vào vị trí đúng */
        arr[j + 1] = k;
    }
}

void BinaryInsertionSort(int arr[], int n)
{
    // Bắt đầu xét từ phần tử thứ 2
    for (int i = 1; i < n; i++)
    {
        int k = arr[i];
        /* Dùng tìm kiếm nhị phân
        để tìm vị trí đúng của
        phẩn tử đang xét */
        int low = 0;
        int high = i - 1;
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] <= k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        /* Chuyển các phần tử lớn hơn
        phần tử đang xét sang phải
        1 lần so với vị trí hiện tại */
        for (int j = i - 1; j >= low; j--)
        {
            arr[j + 1] = arr[j];
        }
        // Chèn vào đúng vị trí
        arr[low] = k;
    }
}

void ShellSort(int arr[], int n)
{
    // Tạo gap và bước nhảy của nó
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Chia thành các dãy cách nhau 1 khoảng gap
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            // Insertion Sort với các phần tử cách nhau bởi gap
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
void SelectionSort(int arr[], int n)
{
    // Xét từng vị trí trong mảng
    for (int i = 0; i < n; i++)
    {
        int pos = i;
        /* Tìm phần tử nhỏ nhất
        từ vị trí i tới n */
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[i])
                pos = j;
        }
        /* Đưa phần tử thứ i
        về đúng vị trí */
        swap(arr[i], arr[pos]);
    }
}
void Heapify(int arr[], int n, int i)
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

void HeapSort(int arr[], int n)
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

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1, n2 = right - mid;
    int L[100], R[100];
    // Chia mảng ban đầu thành hai mảng con
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;
    /* Hợp nhất hai mảng con này
    tạo thành mảng mới được sắp xếp*/
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    /* Sao chép những phần tử còn lại của
    mảng con bên trái nếu còn */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    /* Sao chép những phần tử còn lại của
    mảng con bên phải nếu còn */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

bool isSorted(int arr[], int left, int right)
{
    for (int i = left; i < right; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}

void MergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return;
    if (isSorted(arr, left, right))
        return;
    /*Chia ra hai mảng từ left sang right
    rồi đệ quy sắp xếp hai mảng đó và hợp nhất*/
    int mid = left + (right - left) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void MergeArrays(vector<int> &a, vector<int> &b, vector<int> &c)
{
    int i = 0, j = 0, k = 0;
    int n1 = a.size();
    int n2 = b.size();
    c.resize(n1 + n2);
    // Duyệt qua cả hai mảng
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = b[i];
            k++;
            i++;
        }
    }
    // Duyệt các phần tử còn lại của a
    while (i < n1)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    // Duyệt các phần tử còn lại của b
    while (j < n2)
    {
        c[k] = b[i];
        k++;
        i++;
    }
}

void MergeKArrays1(vector<vector<int>> &arr, int low, int high, vector<int> &res)
{
    // Nếu chỉ còn một mảng
    if (low == high)
    {
        res = arr[low];
        return;
    }
    // Nếu chỉ còn hai mảng, hợp nhất chúng
    if (high - low == 1)
    {
        MergeArrays(arr[low], arr[high], res);
        return;
    }
    int mid = (low + high) / 2;
    // Chia mảng thành hai mảng con
    vector<int> out1, out2;
    MergeKArrays1(arr, low, mid, out1);
    MergeKArrays1(arr, mid + 1, high, out2);
    // Hợp nhất hai mảng con lại
    MergeArrays(out1, out2, res);
}

vector<int> MergeKArrays2(vector<vector<int>> arr)
{
    vector<int> output;
    // Đây là MinHeap với mỗi node đều có phần tử đầu tiên của mảng
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

    for (int i = 0; i < arr.size(); i++)
    {
        heap.push({arr[i][0], {i, 0}});
    }
    /* Lần lượt lấy từng phần tử nhỏ nhất từ MinHeap
    và thay thế với phần tử tiếp theo của mảng đó*/
    while (heap.empty() == false)
    {
        pair<int, pair<int, int>> curr = heap.top();
        heap.pop();
        // i là giá trị
        // j là chỉ số của giá trị tương ứng
        int i = curr.second.first;
        int j = curr.second.second;

        output.push_back(curr.first);
        // Phần tử tiếp theo thuộc cùng mảng hiện tại
        if (j + 1 < arr[i].size())
            heap.push({arr[i][j + 1], {i, j + 1}});
    }
    return output;
}

vector<int> CountSort(int arr[], int n)
{
    int m = 0;

    for (int i = 0; i < m; i++)
        m = max(m, arr[i]);
    // Tạo chuỗi đếm m+1 giá trị 0
    vector<int> count(m + 1, 0);
    /* Tương ứng tần suất của từng
    phần tử trong arr qua mảng ount */
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    /* Tính tổng tiền tố của từng
    chỉ số ở mảng count */
    for (int i = 1; i <= m; i++)
        count[i] += count[i - 1];

    // Tạo vector đầu ra dựa trên hàm count
    vector<int> output(n);

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    return output;
}
void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    // lưu trữ số lần xuất hiện trong mảng count
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    /* Thay đổi count[i] để count[i]
    chứa vị trí thực của chữ số trong hàm output */
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    // Xây dựng hàm output
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    // Chép hàm output qua arr
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void RadixSort(int arr[], int n)
{
    // Tìm giá trị lớn nhất trong arr
    int mx = arr[0];
    for (int i = 1; i < n; i++)
    {
        mx = max(mx, arr[i]);
    }
    // Dùng sắp xếp đếm cho từng chữ số
    for (int exp = 1; mx / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver Code
int main()
{
    int arr[] = {10, 7, 8, 9, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    HeapSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}