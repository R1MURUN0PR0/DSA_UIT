#include <bits/stdc++.h>
using namespace std;

void printres(vector<int> &arr){
    for(int i = arr.size() - 1; i >= 0; i--) cout << arr[i];
}
void printpattern(int n){
    for(int i = 0; i < n; i++) cout << 0;
}

vector<int> splitDigits(string s){
    vector<int> digits;
    // Chuyển ký tự thành số
    for (char c : s) digits.push_back(c - '0');
    return digits;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    
    vector<int> digits = splitDigits(s);
    int n = digits.size();
    sort(digits.begin(), digits.end());

    int sum = accumulate(digits.begin(), digits.end(), 0);
    vector<int> mod1, mod2;

    for (int d : digits) {
        if (d % 3 == 1) mod1.push_back(d);
        else if (d % 3 == 2) mod2.push_back(d);
    }

    if (sum % 3 == 0) {
        printres(digits);
        return 0;
    }

    if (sum % 3 == 1) {
        if (!mod1.empty()) {
            digits.erase(find(digits.begin(), digits.end(), mod1[0]));
            printres(digits);
            return 0;
        }
        if (mod2.size() >= 2) {
            digits.erase(find(digits.begin(), digits.end(), mod2[0]));
            digits.erase(find(digits.begin(), digits.end(), mod2[1]));
            printres(digits);
            return 0;
        }
    } 
    else { // sum % 3 == 2
        if (!mod2.empty()) {
            digits.erase(find(digits.begin(), digits.end(), mod2[0]));
            printres(digits);
            return 0;
        }
        if (mod1.size() >= 2) {
            digits.erase(find(digits.begin(), digits.end(), mod1[0]));
            digits.erase(find(digits.begin(), digits.end(), mod1[1]));
            printres(digits);
            return 0;
        }
    }
    printpattern(n);
    return 0;
}