#include <bits/stdc++.h>
using namespace std;

struct Line {
    string text;
    Line* prev;
    Line* next;
    Line(string t) : text(t), prev(nullptr), next(nullptr) {}
};

class TextEditor {
private:
    Line* head;
    Line* current; // Dòng hiện tại
public:
    TextEditor() : head(nullptr), current(nullptr) {}

    // Thêm dòng mới sau dòng hiện tại
    void addLine(string text) {
        Line* newLine = new Line(text);
        if (!head) {
            head = current = newLine;
            return;
        }
        newLine->next = current->next;
        newLine->prev = current;
        if (current->next) {
            current->next->prev = newLine;
        }
        current->next = newLine;
        current = newLine;
    }

    // Xóa dòng hiện tại
    void deleteLine() {
        if (!current) {
            cout << "Không có dòng nào!\n";
            return;
        }
        Line* temp = current;
        if (current->prev) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        if (current->next) {
            current->next->prev = current->prev;
        }
        current = current->next ? current->next : current->prev;
        delete temp;
    }

    // Di chuyển lên
    void moveUp() {
        if (current && current->prev) {
            current = current->prev;
        }
    }

    // Di chuyển xuống
    void moveDown() {
        if (current && current->next) {
            current = current->next;
        }
    }

    // Hiển thị văn bản
    void displayText() {
        Line* temp = head;
        int lineNum = 1;
        while (temp) {
            cout << lineNum++ << ": " << temp->text << endl;
            temp = temp->next;
        }
        cout << "Dòng hiện tại: " << (current ? current->text : "Trống") << endl;
    }
};

int main() {
    TextEditor editor;
    int num;
    cout << "CẢM ƠN BẠN ĐÃ SỬ DỤNG SẢN PHẨM CỦA TÔI ^^\n";
    cout << "Nhấn phím để lựa chọn hoạt động:\n";
    cout << "1: Thêm hoặc xóa dòng\n";
    cout << "2: Hiển thị liên lạc hiện tại\n";
    cout << "3: Di chuyển\n";
    cout << "4: Ngưng sử dụng\n";
    while(true){
        cout << "Vui lòng nhập số để sử dụng: ";
        cin >> num;
        if(num == 1){
            int t;
            cout << "Nhấn phím 0 để xóa dòng\n";
            cout << "Nhấn phím 1 để thêm dòng\n";
            cout << "Vui lòng nhập số để sử dụng: ";
            cin >> t;
            cin.ignore();
            if(t == 1){
                string text;
                cout << "Nhập nội dung: ";
                getline(cin, text);
                editor.addLine(text);
            }
            else if(t == 0) editor.deleteLine();
            else cout << "Vui lòng nhập chỉ 0 hoặc 1!!!\n";
        }
        if(num == 2) editor.displayText();
        if(num == 3){
            int choice;
            cout << "Nhấn phím 0 để di chuyển xuống\n";
            cout << "Nhấn phím 1 để di chuyển lên\n";
            cin >> choice;
            if(choice == 0) editor.moveDown();
            else if(choice == 1) editor.moveUp();
            else cout << "Vui lòng nhập chỉ 0 hoặc 1!!!\n";
        }
        if(num == 4) return 0;
    }
}