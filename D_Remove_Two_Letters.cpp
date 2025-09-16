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

ll po1[N], pre1[N], po2[N], pre2[N];
ll mod1 = 1e9 + 7, mod2 = 998244353;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    set<pi> st;

    s = '#' + s;
    ll h1 = 0, h2 = 0, p = 31;
    po1[0] = 1, po2[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        po1[i] = p * po1[i - 1] % mod1;
        h1 = h1 * p % mod1 + (s[i] - 'a' + 1);
        pre1[i] = h1;

        po2[i] = p * po2[i - 1] % mod2;
        h2 = h2 * p % mod2 + (s[i] - 'a' + 1);
        pre2[i] = h2;
    }
    for (int i = 2; i <= n; i++)
    {
        ll x = (pre1[n] - pre1[i] * po1[n - i] % mod1 + mod1) % mod1 + pre1[i - 2] * po1[n - i] % mod1;
        x %= mod1;

        ll y = (pre2[n] - pre2[i] * po2[n - i] % mod2 + mod2) % mod2 + pre2[i - 2] * po2[n - i] % mod2;
        y %= mod2;

        st.insert({x, y});
    }

    cout << st.size() << endl;
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