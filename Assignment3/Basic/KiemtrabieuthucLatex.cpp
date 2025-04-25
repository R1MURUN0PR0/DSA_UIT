#include <bits/stdc++.h>
using namespace std;

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
    getline(cin, s);
    vector<char> v;
    for (auto &c : s)
    {
        if (c == '{' || c == '(' || c == '[')
            v.push_back(c);

        else if (c == '}' || c == ')' || c == ']')
        {
            if (v.empty())
            {
                cout << '0';
                return 0;
            }
            char top = v.back();
            v.pop_back();
            if ((c == '}' && top != '{') || (c == ')' && top != '(') || (c == ']' && top != '['))
            {
                cout << '0';
                return 0;
            }
        }
    }
    if (!v.empty())
        cout << '0';
    else
        cout << '1';

    return 0;
}