#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1e5 + 1;
int MOD = 1e9 + 7;

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
const int LIM = 1e5;
int fact[MAX], ifact[MAX];

void prepare()
{
    // Tính fact[]
    fact[0] = 1;
    for (int i = 1; i <= LIM; i++)
        fact[i] = fact[i - 1] * i % MOD;

    // Tính ifact[]
    ifact[MOD - 1] = binpow(fact[MOD - 1], MOD - 2);
    for (int i = MOD - 2; i >= 0; i--)
        ifact[i] = (ifact[i + 1] * (i + 1)) % MOD;
}

// Hàm tính nCk
int C(int n, int k)
{
    if (k > n) return 0;
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
    int t, n;
    cin >> t >> MOD;
    prepare();

    while(t--){
        cin >> n;
        int K = n - 1;
        int N = 2*n - 1;
        int res = 1;
        while(N > 0){
            int N1 = N % MOD;
            int K1 = K % MOD;
    
            N /= MOD;
            K /= MOD;

            res = res * C(N1 , K1) % MOD;
        }
    
        cout << res << "\n";
    }

    return 0;
}