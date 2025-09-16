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
    string s, t;
    cin >> s;

    int j = s.size() - 1;
    while (j >= 0 && s[j] == '1')
        t += '1', j--;

    ll mx = j != s.size() - 1;
    for (int i = 0; i <= j; i++)
    {
        t += s[i];
        mx |= s[i] == '1';
    }

    if (j == -1)
        mx = 1ll * s.size() * s.size();
    ll cnt = 1;
    for (size_t i = 1; i < t.size(); i++)
    {
        if ((t[i - 1] == '1' && t[i] == t[i - 1]))
        {
            cnt++;
            mx = max(mx, ((cnt + 1) / 2) * ((cnt + 1) / 2));
            mx = max(mx , (cnt / 2) * (cnt / 2 + 1));
        }
        else
            cnt = 1;
    }
    cout << mx << endl;
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