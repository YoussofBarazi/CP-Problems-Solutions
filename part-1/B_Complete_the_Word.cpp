#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define oo INT_MAX
#define OO LONG_MAX
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend()
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

    bool ok = false;
    const string x = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i <= int(s.size()) - 26; i++)
    {
        set<char> exist;

        int cnt = 0;
        for (int j = i; j < i + 26; j++)
        {
            if (s[j] == '?')
                cnt++;
            else
                exist.insert(s[j]);
        }

        if (26 == cnt + exist.size())
        {
            for (int j = i; j < i + 26; j++)
            {
                if (s[j] == '?')
                    for (int i = 0; i < x.size(); i++)
                    {
                        if (exist.find(x[i]) == exist.end())
                        {
                            s[j] = x[i];
                            exist.insert(s[j]);
                            break;
                        }
                    }
            }

            ok = true;
            break;
        }
    }

    if (ok)
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '?')
                s[i] = 'A';
        }
        cout << s << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    IOS;

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}