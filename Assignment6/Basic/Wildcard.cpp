#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using ll = long long;
using H = pair<ll, ll>;

const ll M1 = 998244353, M2 = 1000000007;
const ll B1 = 307, B2 = 311;
vector<H> h, p;

struct Hash
{
    void build(string s)
    {
        int n = s.size();
        h.assign(n + 1, {0, 0});
        p.assign(n + 1, {1, 1});
        for (int i = 1; i <= n; ++i)
        {
            p[i] = {p[i - 1].fi * B1 % M1,
                    p[i - 1].se * B2 % M2};
            h[i] = {(h[i - 1].fi * B1 + s[i - 1] + 3) % M1,
                    (h[i - 1].se * B2 + s[i - 1] + 3) % M2};
        }
    }
    H get(int l, int r) 
    {
        if (l > r)
            return {0, 0};
        ll x = (h[r].fi - h[l - 1].fi * p[r - l + 1].fi + M1 * M1) % M1;
        ll y = (h[r].se - h[l - 1].se * p[r - l + 1].se + M2 * M2) % M2;
        return {x, y};
    }
} hs;

/* ---------- thống kê ---------- */
map<H, int> pre, suf, full;
map<pair<H, H>, int> mp_ps; // (prefix-hash , suffix-hash)

void add_string(string s)
{
    hs.build(s);
    int n = s.size();

    full[hs.get(1, n)]++; // khớp hoàn toàn
    for (int i = 1; i <= n; ++i)
    {
        pre[hs.get(1, i)]++;
        suf[hs.get(i, n)]++;
        for (int j = i + 1; j <= n; ++j) // vị trí '*' giữa i và j-1
            mp_ps[{hs.get(1, i), hs.get(j, n)}]++;
    }
}

/* ---------- truy vấn ---------- */
int query(string s, int n)
{
    if (s.empty()) return 0;
    hs.build(s);
    int m = s.size();
    if (s == "*")
        return n;
    if (s.find('*') == -1)
        return full[hs.get(1, m)];
    if (s[0]== '*')
        return suf[hs.get(2, m)];
    if (s[m - 1] == '*')
        return pre[hs.get(1, m - 1)];

    int k = s.find('*');
    return mp_ps[{hs.get(1, k), hs.get(k + 2, m)}];
}

/* ---------- main ---------- */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r"))
    {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
    int n, q;
    cin >> n >> q;
    string s;
    getline(cin, s);
    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);
        add_string(s);
    }
    while (q--)
    {
        string s;
        getline(cin, s);
        cout << query(s, n) << '\n';
    }
    return 0;
}
