#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

void solve()
{
    string s;
    cin >> s;

    set<int> small, capital, remove;
    string ans;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'b' && small.size())
        {
            auto x = small.end();
            x--;
            s[*x] = '.';
            small.erase(x);
        }
        else if (s[i] == 'B' && capital.size())
        {
            auto x = capital.end();
            x--;
            s[*x] = '.';
            capital.erase(x);
        }
        else 
        {
            if (s[i] >= 'a')
                small.insert(i);
            else 
                capital.insert(i);
        }
    }

    for (int i = 0 ; i < s.size() ; i ++)
    {
        if (s[i] != '.' && s[i] != 'B' && s[i] != 'b')
            cout << s[i];
    }
    cout << endl;
}

int main()
{
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}