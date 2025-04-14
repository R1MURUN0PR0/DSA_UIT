#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
    Contact* prev;
    Contact* next;
    Contact(string n, string p) : name(n), phone(p), prev(nullptr), next(nullptr) {}
};

class ContactList {
private:
    Contact* head;
    Contact* current; // Con trỏ đến liên lạc
public:
    ContactList() : head(nullptr), current(nullptr) {}

    // Thêm liên lạc mới
    void addContact(string name, string phone) {
        Contact* newContact = new Contact(name, phone);
        if (!head) {
            head = current = newContact;
            return;
        }
        Contact* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newContact;
        newContact->prev = temp;
    }

    // Di chuyển lên (liên lạc trước)
    string moveUp() {
        if (!current || !current->prev) {
            return "Đã ở đầu danh sách!";
        }
        current = current->prev;
        return current->name + " (" + current->phone + ")";
    }

    // Di chuyển xuống (liên lạc sau)
    string moveDown() {
        if (!current || !current->next) {
            return "Đã ở cuối danh sách!";
        }
        current = current->next;
        return current->name + " (" + current->phone + ")";
    }

    // Hiển thị liên lạc hiện tại
    string getCurrent() {
        return current ? current->name + " (" + current->phone + ")" : "Danh sách trống!";
    }
};

int main() {
    ContactList contacts;
    int num;
    cout << "CẢM ƠN BẠN ĐÃ SỬ DỤNG SẢN PHẨM CỦA TÔI ^^\n";
    cout << "Nhấn phím để lựa chọn hoạt động:\n";
    cout << "1: Thêm liên lạc\n";
    cout << "2: Hiển thị liên lạc hiện tại\n";
    cout << "3: Di chuyển\n";
    cout << "4: Ngưng sử dụng\n";
    while(true){
        cout << "Vui lòng nhập số để sử dụng: ";
        cin >> num;
        if(num == 1){
            int t;
            cout << "Nhập số lượng thêm: ";
            cin >> t;
            while(t--){
                cin.ignore();
                string name, phone;
                cout << "Nhập tên: ";
                getline(cin, name);
                cout << "Nhập số liên lạc: ";
                cin >> phone;
                contacts.addContact(name, phone);
            }
        }
        if(num == 2) cout << contacts.getCurrent() << endl;;
        if(num == 3){
            int choice;
            cout << "Nhấn phím 0 để di chuyển xuống\n";
            cout << "Nhấn phím 1 để di chuyển lên\n";
            cin >> choice;
            if(choice == 0) cout << contacts.moveDown() << endl;
            else if(choice == 1) cout << contacts.moveUp() << endl;
            else cout << "Vui lòng nhập chỉ 0 hoặc 1!!!\n";
        }
        if(num == 4) return 0;
    }
}