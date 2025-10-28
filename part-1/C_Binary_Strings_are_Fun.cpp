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

const int N = 200009;

ll mod = 998244353;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    s = '#' + s;

    ll ans = 0, cur = 1;

    for (int i = 1; i <= n; i++)
    {
        if (s[i] == s[i - 1])
            cur *= 2;
        else
            cur = 1;

        cur %= mod;
        ans += cur;
        ans %= mod;
    }

    cout << ans << endl;
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