#include <bits/stdc++.h>
using namespace std;

struct Call {
    string phoneNumber;
    string time;
    Call(string phone, string t) : phoneNumber(phone), time(t) {}
};

class CallCenter {
private:
    queue<Call> calls;
public:
    // Thêm cuộc gọi mới
    void addCall(string phoneNumber, string time) {
        calls.push(Call(phoneNumber, time));
    }

    // Xử lý cuộc gọi đầu tiên
    void handleCall() {
        if (calls.empty()) {
            cout << "Không có cuộc gọi nào!\n";
            return;
        }
        Call call = calls.front();
        cout << "Xử lý cuộc gọi từ " << call.phoneNumber << " lúc " << call.time << endl;
        calls.pop();
    }

    // Hiển thị hàng đợi
    void displayQueue() {
        queue<Call> temp = calls;
        if (temp.empty()) {
            cout << "Hàng đợi trống!\n";
            return;
        }
        cout << "Hàng đợi cuộc gọi:\n";
        while (!temp.empty()) {
            Call call = temp.front();
            cout << call.phoneNumber << " (lúc " << call.time << ")\n";
            temp.pop();
        }
    }
};

int main() {
    CallCenter center;
    int num;
    cout << "CẢM ƠN BẠN ĐÃ SỬ DỤNG SẢN PHẨM CỦA TÔI ^^\n";
    cout << "Nhấn phím để lựa chọn hoạt động:\n";
    cout << "1: Thêm cuộc gọi mới\n";
    cout << "2: Xử lý cuộc gọi đầu tiên\n";
    cout << "3: Hiển thị\n";;
    cout << "4: Ngưng sử dụng\n";

    while(true){
        cout << "Vui lòng nhập số để sử dụng: ";
        cin >> num;
        if(num == 1){
            string phoneNumber, time;
            cout << "Nhập số điện thoại và thời gian: ";
            cin >> phoneNumber >> time;
            center.addCall(phoneNumber, time);
        }
        if(num == 2) center.handleCall();
        if(num == 3) center.displayQueue();
        if(num == 4) return 0;
    }
}