#include <bits/stdc++.h>
using namespace std;

struct Customer {
    string name;
    int groupSize;
    Customer* next;
    Customer(string n, int size) : name(n), groupSize(size), next(nullptr) {}
};

class Waitlist {
private:
    Customer* head;
public:
    Waitlist() : head(nullptr) {}

    // Thêm khách vào cuối danh sách
    void addCustomer(string name, int groupSize) {
        Customer* newCustomer = new Customer(name, groupSize);
        if (!head) {
            head = newCustomer;
            return;
        }
        Customer* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newCustomer;
    }

    // Gọi người ở đầu tiên
    void callNext() {
        if (!head) {
            cout << "Danh sách trống!\n";
            return;
        }
        Customer* temp = head;
        cout << "Gọi: " << temp->name << " (Nhóm " << temp->groupSize << " người)\n";
        head = head->next;
        delete temp;
    }

    // Hiển thị danh sách
    void displayWaitlist() {
        Customer* temp = head;
        if (!temp) {
            cout << "Danh sách trống!\n";
            return;
        }
        cout << "Danh sách:\n";
        while (temp) {
            cout << temp->name << " (Nhóm " << temp->groupSize << " người)\n";
            temp = temp->next;
        }
    }
};

int main() {
    Waitlist KFC;
    int num;
    cout << "CHÂN THÀNH CẢM ƠN KFC ĐÃ SỬ DỤNG SẢN PHẨM CỦA TÔI ^^\n";
    cout << "Nhấn phím để lựa chọn hoạt động:\n";
    cout << "1: Đặt bàn\n";
    cout << "2: Hiển thị danh sách đã đặt bàn hiện tại\n";
    cout << "3: Gọi khách\n";
    cout << "4: Ngưng sử dụng\n";
    while(true){
        cout << "Vui lòng nhập số để sử dụng: ";
        cin >> num;
        if(num == 1){
            int t;
            cout << "Nhập số lượng nhóm đặt: ";
            cin >> t;
            while(t--){
                cin.ignore();
                string name;
                int groupSize;
                cout << "Nhập tên: ";
                getline(cin, name);
                cout << "Nhập số lượng người: ";
                cin >> groupSize;
                KFC.addCustomer(name, groupSize);
            }
        }
        if(num == 2) KFC.displayWaitlist();
        if(num == 3) KFC.callNext();
        if(num == 4) return 0;
    }
}