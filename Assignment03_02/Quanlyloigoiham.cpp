#include <bits\stdc++.h>
using namespace std;

struct FunctionCall {
    string funcName;
    string params;
    FunctionCall(string name, string p) : funcName(name), params(p) {}
};

class CallStack {
private:
    stack<FunctionCall> calls;
public:
    // Gọi hàm
    void callFunction(string funcName, string params) {
        calls.push(FunctionCall(funcName, params));
        cout << "Gọi: " << funcName << "(" << params << ")\n";
    }

    // Kết thúc hàm
    void returnFunction() {
        if (calls.empty()) {
            cout << "Stack rỗng!\n";
            return;
        }
        FunctionCall call = calls.top();
        calls.pop();
        cout << "Trả về từ: " << call.funcName << "(" << call.params << ")\n";
    }

    // Hiển thị stack
    void displayStack() {
        stack<FunctionCall> temp = calls;
        cout << "Call Stack (từ đỉnh):\n";
        while (!temp.empty()) {
            FunctionCall call = temp.top();
            cout << call.funcName << "(" << call.params << ")\n";
            temp.pop();
        }
    }
};
int main() {
    CallStack stack;
    int num;
    cout << "CẢM ƠN BẠN ĐÃ SỬ DỤNG SẢN PHẨM CỦA TÔI ^^\n";
    cout << "Nhấn phím để lựa chọn hoạt động:\n";
    cout << "1: Gọi hàm\n";
    cout << "2: Kết thúc hàm\n";
    cout << "3: Hiển thị\n";;
    cout << "4: Ngưng sử dụng\n";

    while(true){
        cout << "Vui lòng nhập số để sử dụng: ";
        cin >> num;
        if(num == 1){
            string funcName, params;
            cout << "Nhập hàm và biến số: ";
            cin >> funcName >> params;
            stack.callFunction(funcName, params);
        }
        if(num == 2) stack.returnFunction();
        if(num == 3) stack.displayStack();
        if(num == 4) return 0;
    }
}