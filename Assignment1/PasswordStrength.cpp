#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const signed BaseScore = 40;
const signed Bonus_Excess = 3;
const signed Bonus_Upper = 4;
const signed Bonus_Number = 5;
const signed Bonus_Symbols = 5;
signed Bonus_Combo;
signed Bonus_FlatNumber;
signed Bonus_FlatLower;
signed Number_Upper;
signed Number_Lower;
signed Number_Numbers;
signed Number_Symbols;
signed Number_dif;

bool issymbol(char c)
{
    vector<char> symbol = {'!', '@', '#', '$', '%', '^', '&', '*', '?', '_', '~'};
    for (char p : symbol)
    {
        if (c == p)
            return true;
    }
    return false;
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
    string s;
    cin >> s;
    const signed n = s.size();
    signed Number_Excess = n - 8;
    if (n < 8)
    {
        cout << "KhongHopLe";
        return 0;
    }
    for (signed i = 0; i < n; i++)
    {
        if (isupper(s[i]))
            Number_Upper++;
        else if (islower(s[i]))
            Number_Lower++;
        else if (isdigit(s[i]))
            Number_Numbers++;
        else if (issymbol(s[i]))
            Number_Symbols++;
        else
        {
            cout << "KhongHopLe";
            return 0;
        }
    }

    // Đặt số Bonus_Combo theo đề
    if (Number_Upper > 0 && Number_Symbols > 0 && Number_Numbers > 0)
        Bonus_Combo = 25;
    else if ((Number_Upper > 0 && Number_Symbols > 0) || (Number_Symbols > 0 && Number_Numbers > 0) || (Number_Upper > 0 && Number_Numbers > 0))
        Bonus_Combo = 15;
    else if (Number_Upper == 0 && Number_Symbols == 0 && Number_Numbers == 0)
        Bonus_Combo = 0;

    // Đặt số Bonus_FlatLower theo đề
    if (Number_Lower == n)
        Bonus_FlatLower = -15;
    else
        Bonus_FlatLower = 0;

    // Đặt số Bonus_FlatNumber theo đề
    if (Number_Numbers == n)
        Bonus_FlatNumber = -35;
    else
        Bonus_FlatLower = 0;

    int point = BaseScore + Number_Excess * Bonus_Excess + Number_Upper * Bonus_Upper + Number_Numbers * Bonus_Number + Number_Symbols * Bonus_Symbols + Bonus_Combo + Bonus_FlatLower + Bonus_FlatNumber;
    if (point < 50)
        cout << "Yeu";
    else if (point < 75)
        cout << "Vua";
    else if (point < 100)
        cout << "Manh";
    else
        cout << "RatManh";
    return 0;
}