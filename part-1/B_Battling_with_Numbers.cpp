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

ll MOD(ll x, ll mod)
{
    return (x % mod + mod) % mod;
}

ll POW_M(ll x, ll y, ll mod)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return MOD(x, mod);

    ll ans = POW_M(x, y / 2, mod);

    if (y & 1)
        return MOD(MOD(ans * ans, mod) * x, mod);
    return MOD(ans * ans, mod);
}

void solve()
{
    int n;
    cin >> n;

    map<int, int> x, y;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int w;
        cin >> w;

        x[a[i]] = w;
    }

    int m;
    cin >> m;

    a.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        int w;
        cin >> w;

        y[a[i]] = w;
    }

    bool ok = true;
    for (auto i : y)
    {
        if (i.S > x[i.F])
        {
            ok = false;
            break;
        }
    }

    if (!ok)
    {
        cout << 0 << endl;
        return;
    }

    int cnt = 0;

    for (auto i : x)
    {
        cnt += (i.S == y[i.F]);
    }

    ll ans = POW_M(2, max(x.size(), y.size()) - cnt, 998244353);

    cout << ans << endl;
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