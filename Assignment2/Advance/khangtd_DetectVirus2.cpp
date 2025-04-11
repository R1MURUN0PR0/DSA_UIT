#include <bits/stdc++.h>
using namespace std;

vector<int> KMP(string &s, string &t) {
    int m = s.size(), n = t.size();
    vector<int> LPS(n, 0), pos;
    // Coding LPS
    int preLPS = 0, i = 1;
    while(i < n){
        if (t[i] == t[preLPS]){
            LPS[i] = preLPS + 1;
            preLPS++;
            i++;
        }
        else if (preLPS == 0){
            LPS[i] = 0;
            i++;
        }
        else preLPS = LPS[preLPS - 1];
    }
    // Coding KMP
    i = 0;
    int j = 0;
    while(i < m){
        if(s[i] == t[j]) i++, j++;
        else j ? j = LPS[j - 1] : i++;
        if(j == n) pos.push_back(i - j + 1);
    }
    return pos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r"))
    {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
    
    string s, t;
    cin >> s >> t;

    if (t.size() > s.size()) {
        cout << "NO";
        return 0;
    }

    vector<int> pos = KMP(s, t);

    if (pos.empty()) cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i : pos) cout << i << " ";
    }
    return 0;
}
