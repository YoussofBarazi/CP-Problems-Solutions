#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
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

const int N = 1000009;

ll p1[N], p2[N], pref1[N], pref2[N], mod1 = 1e9 + 7, mod2 = 998244353;

void calc(string s)
{
    p1[0] = p2[0] = 1;

    for (int i = 1; i < s.size(); i++)
    {
        p1[i] = p1[i - 1] * 29 % mod1;
        p2[i] = p2[i - 1] * 29 % mod2;

        pref1[i] = (pref1[i - 1] * 29 + s[i] - 'a' + 1) % mod1;
        pref2[i] = (pref2[i - 1] * 29 + s[i] - 'a' + 1) % mod2;
    }
}

pair<int, int> get(int l, int r)
{
    int ans1 = (pref1[r] - pref1[l - 1] * p1[r - l + 1] % mod1 + mod1) % mod1;
    int ans2 = (pref2[r] - pref2[l - 1] * p2[r - l + 1] % mod2 + mod2) % mod2;

    return {ans1, ans2};
}

void solve()
{
    string s;
    cin >> s;

    s = '#' + s;

    calc(s);

    vector<int> possible;
    for (int i = 1; i < s.size() - 1; i++)
    {
        if (get(1, i) == get(s.size() - i, s.size() - 1))
            possible.pb(i);
    }

    if (possible.size() == 0)
    {
        cout << "Just a legend" << endl;
        return;
    }

    reverse(all(possible));

    int len = possible[0];

    pair<int, int> ans1 = get(1, len);

    for (int i = len + 1; i < s.size() - 1; i++)
    {
        if (get(i - len + 1, i) == ans1)
        {
            cout << s.substr(1, len) << endl;
            return;
        }
    }

    if (possible.size() == 1)
    {
        cout << "Just a legend" << endl;
        return;
    }

    len = possible[1];
    ans1 = get(1, len);

    for (int i = len + 1; i < s.size() - 1; i++)
    {
        if (get(i - len + 1, i) == ans1)
        {
            cout << s.substr(1, len) << endl;
            return;
        }
    }

    cout << "Just a legend" << endl;
}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}