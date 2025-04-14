#include <bits/stdc++.h>
using namespace std;

struct Event {
    string type;
    string data;
    Event(string t, string d) : type(t), data(d) {}
};

class EventLoop {
private:
    queue<Event> events;
public:
    // Thêm sự kiện mới
    void addEvent(string type, string data) {
        events.push(Event(type, data));
    }

    // Xử lý sự kiện đầu tiên
    void processEvent() {
        if (events.empty()) {
            cout << "Không có sự kiện nào!\n";
            return;
        }
        Event evt = events.front();
        cout << "Xử lý sự kiện: " << evt.type << " với dữ liệu: " << evt.data << endl;
        events.pop();
    }

    // Hiển thị hàng đợi
    void displayQueue() {
        queue<Event> temp = events;
        if (temp.empty()) {
            cout << "Hàng đợi trống!\n";
            return;
        }
        cout << "Hàng đợi sự kiện:\n";
        while (!temp.empty()) {
            Event evt = temp.front();
            cout << evt.type << ": " << evt.data << endl;
            temp.pop();
        }
    }
};

int main() {
    EventLoop loop;
    int num;
    cout << "CẢM ƠN BẠN ĐÃ SỬ DỤNG SẢN PHẨM CỦA TÔI ^^\n";
    cout << "Nhấn phím để lựa chọn hoạt động:\n";
    cout << "1: Thêm sự kiện mới\n";
    cout << "2: Xử lý sự kiện đầu tiên\n";
    cout << "3: Hiển thị\n";;
    cout << "4: Ngưng sử dụng\n";

    while(true){
        cout << "Vui lòng nhập số để sử dụng: ";
        cin >> num;
        if(num == 1){
            string type, data;
            cout << "Nhập số điện thoại và thời gian: ";
            cin >> type >> data;
            loop.addEvent(type, data);
        }
        if(num == 2) loop.processEvent();
        if(num == 3) loop.displayQueue();
        if(num == 4) return 0;
    }
}