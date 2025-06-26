#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 40 + 2;

int t[N], n , x;
vector<ll> A, B;

void findsum(int i, int sum, int n, vector<ll>& v) {
    if (sum > x) return;

    if (i > n) v.push_back(sum);
    else {
        findsum(i + 1, (ll) sum, n, v);
        findsum(i + 1, (ll) sum + t[i], n, v);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r"))
    {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> t[i];

    // Tất cả các cặp tổng của hai mảng
    findsum(1, 0, n / 2, A);
    findsum(n / 2 + 1, 0, n, B);

    // Sắp xếp mảng B
    sort(B.begin(), B.end());

    // Lặp qua mảng A và tìm kiếm nhị phân:
    // - Đếm số lượng phần tử trong B có giá trị bằng x - A[i]
    ll cnt = 0;
    for (ll sum : A) {
        cnt += upper_bound(B.begin(), B.end(), x - sum)
             - lower_bound(B.begin(), B.end(), x - sum);
    }
    cout << cnt << '\n';
    return 0;
}