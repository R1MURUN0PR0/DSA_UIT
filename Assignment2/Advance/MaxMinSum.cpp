#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 1;
const int MOD = 1e9 + 7;
int fact[N], ifact[N];

int binpow(int a, int b)
{
    if (b <= 0)
        return 1;
    if (b == 1)
        return a;

    int p = binpow(a, b / 2);

    if (b % 2 == 0)
        return p * p % MOD;
    return p * p % MOD * a % MOD;
}
// Chuẩn bị
void prepare()
{
    // Tính fact[]
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = fact[i - 1] * i % MOD;

    // Tính ifact[]
    ifact[N] = binpow(fact[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--)
        ifact[i] = ifact[i + 1] * (i + 1) % MOD;
}

// Hàm tính nCk
int C(int n, int k)
{
    return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r"))
    {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
    prepare();
    int n, k, a[N];
    cin >> n >> k;
    int sum = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);

    for (int i = k; i <= n; i++)
        sum = (sum + a[i] * C(i - 1, k - 1)) % MOD;
    for (int i = 1; i <= n - k + 1; i++)
        sum = ((sum - a[i] * C(n - i, k - 1)) % MOD + MOD) % MOD;
    cout << sum;
    return 0;
}