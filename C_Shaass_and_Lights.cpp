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

ll mod = 1e9 + 7;

ll MOD(ll x)
{
    return (x % mod + mod) % mod;
}

ll POW_M(ll x, ll y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return MOD(x);

    ll ans = POW_M(x, y / 2);

    if (y & 1)
        return MOD(MOD(ans * ans) * x);
    return MOD(ans * ans);
}

ll inv(ll n)
{
    return POW_M(n, mod - 2);
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> on(m);
    for (int i = 0; i < m; i++)
        cin >> on[i];

    vector<ll> fact(n + 1, 1);
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;

    sort(all(on));

    int cnt = on[0] - 1 + n - on[m - 1];
    ll t = fact[on[0] - 1] * fact[n - on[m - 1]] % mod;

    for (int i = 1; i < m; i++)
    {
        cnt += on[i] - on[i - 1] - 1;
        t *= fact[on[i] - on[i - 1] - 1];
        t %= mod;
    }

    ll ans = fact[cnt] * inv(t) % mod;

    for (int i = 1; i < m; i++)
    {
        int x = on[i] - on[i - 1] - 2;

        if (x > 0)
            ans *= POW_M(2, x);

        ans %= mod;
    }

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