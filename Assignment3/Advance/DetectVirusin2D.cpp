#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

// Cơ số dùng cho Kabin-Karp
const ull BASE = 131; 

// Hàm tính prefix hash cho một chuỗi
vector<ull> computePrefixHash(const string &s) {
    int n = s.size();
    vector<ull> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] * BASE + s[i];
    }
    return prefix;
}

// Hàm tính lũy thừa cho một độ dài nhất định
vector<ull> computePow(int n) {
    vector<ull> pow(n + 1, 1);
    for (int i = 0; i < n; i++) {
        pow[i + 1] = pow[i] * BASE;
    }
    return pow;
}

// Hàm lấy hash của substring s[l, r-1] sử dụng prefix hash đã tính trước.
ull getSubHash(const vector<ull>& prefix, const vector<ull>& pow, int l, int r) {
    return prefix[r] - prefix[l] * pow[r - l];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")) {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }

    int n, m, q;
    cin >> n >> m >> q;

    vector<string> Matrix(n);
    for (int i = 0; i < n; i++) {
        cin >> Matrix[i];
    }

    vector<string> patt(q);
    int max_len = 0;
    for (int i = 0; i < q; i++) {
        cin >> patt[i];
        max_len = max(max_len, (int)patt[i].size());
    }

    // Chuẩn bị mảng lũy thừa với độ dài tối đa là max(m, n) + 1, vì chuỗi hàng có độ dài m, cột có độ dài n.
    int maxSize = max(m, n);
    vector<ull> pow = computePow(maxSize);

    // Sử dụng vector của unordered_set để lưu các hash theo độ dài
    // lst_hash[len] sẽ chứa tất cả hash của các chuỗi con có độ dài = len.
    vector<unordered_set<ull>> lst_hash(max_len + 1);

    // Xét từng hàng:
    for (int i = 0; i < n; i++) {
        const string &row = Matrix[i];
        int lenRow = row.size();
        // Tính prefix hash cho hàng
        vector<ull> prefix = computePrefixHash(row);
        for (int length = 1; length <= max_len && length <= lenRow; length++) {
            for (int j = 0; j <= lenRow - length; j++) {
                ull h = getSubHash(prefix, pow, j, j + length);
                lst_hash[length].insert(h);
            }
        }
    }
    
    // Xét từng cột:
    for (int col = 0; col < m; col++) {
        string colStr;
        colStr.reserve(n);
        for (int row = 0; row < n; row++) {
            colStr.push_back(Matrix[row][col]);
        }
        int lenCol = colStr.size();
        // Tính prefix hash cho cột
        vector<ull> prefix = computePrefixHash(colStr);
        for (int length = 1; length <= max_len && length <= lenCol; length++) {
            for (int j = 0; j <= lenCol - length; j++) {
                ull h = getSubHash(prefix, pow, j, j + length);
                lst_hash[length].insert(h);
            }
        }
    }
    
    // Với mỗi mẫu cần tìm, tính hash và kiểm tra trong tập hợp
    for (int i = 0; i < q; i++) {
        const string &pattern = patt[i];
        // Tính hash của mẫu
        int lenPattern = pattern.size();
        ull hashPat = 0;
        for (char c : pattern) {
            hashPat = hashPat * BASE + c;
        }
        // Nếu tìm thấy, in '1', không tìm thấy in '0'
        cout << (lst_hash[lenPattern].count(hashPat) ? '1' : '0');
    }

    return 0;
}
