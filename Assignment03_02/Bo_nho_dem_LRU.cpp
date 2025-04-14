#include <bits/stdc++.h>
using namespace std;

struct CacheEntry {
    string key;
    int value;
    CacheEntry* next;
    CacheEntry(string k, int v) : key(k), value(v), next(nullptr) {}
};

class LRUCache {
private:
    CacheEntry* head;
    int capacity;
    int size;

public:
    LRUCache(int cap) : head(nullptr), capacity(cap), size(0) {}

    // Truy cập hoặc thêm mục mới
    void access(string key, int value) {
        // Kiểm tra xem key đã tồn tại chưa
        CacheEntry* prev = nullptr;
        CacheEntry* curr = head;
        while (curr && curr->key != key) {
            prev = curr;
            curr = curr->next;
        }

        if (curr) {
            // Nếu key tồn tại, di chuyển lên đầu
            if (prev) {
                prev->next = curr->next;
                curr->next = head;
                head = curr;
            }
            // Cập nhật giá trị
            curr->value = value;
            return;
        }

        // Thêm mục mới
        CacheEntry* newEntry = new CacheEntry(key, value);
        newEntry->next = head;
        head = newEntry;
        size++;

        // Nếu vượt quá dung lượng, xóa mục cuối
        if (size > capacity) {
            CacheEntry* temp = head;
            CacheEntry* newLast = nullptr;
            while (temp->next) {
                newLast = temp;
                temp = temp->next;
            }
            if (newLast) {
                newLast->next = nullptr;
                delete temp;
                size--;
            }
        }
    }

    // Hiển thị
    void displayCache() {
        CacheEntry* temp = head;
        cout << "Bộ nhớ đệm (từ mới nhất):\n";
        while (temp) {
            cout << "Key: " << temp->key << ", Value: " << temp->value << "\n";
            temp = temp->next;
        }
    }
};

int main() {
    int num;
    cout << "CẢM ƠN BẠN ĐÃ SỬ DỤNG SẢN PHẨM CỦA TÔI ^^\n";
    cout << "Nhấn phím để lựa chọn hoạt động:\n";
    cout << "1: Truy cập hoặc thêm mục mới\n";
    cout << "2: Hiển thị bộ nhớ đệm\n";
    cout << "3: Ngưng sử dụng\n";
    cout << "Vui lòng nhập dung lượng cache: \n";
    int capacity;
    cin >> capacity;
    LRUCache cache(capacity);
    while(true){
        cout << "Vui lòng nhập số để sử dụng: ";
        cin >> num;
        if(num == 1){
            int t;
            cout << "Nhập số lượt truy cập: ";
            cin >> t;

            while(t--){
                cin.ignore();
                string key;
                int value;
                cout << "Nhập key: ";
                getline(cin, key);
                cout << "Nhập giá trị: ";
                cin >> value;
                cache.access(key, value);
            }
        }
        if(num == 2) cache.displayCache();
        if(num == 3) return 0;
    }
}