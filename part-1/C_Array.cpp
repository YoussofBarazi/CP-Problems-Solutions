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

ll inv(ll x)
{
    return POW_M(x, mod - 2, mod);
}

vector<ll> fact(2e5 + 7, 1);

ll C(ll n, ll r)
{
    return fact[n] * inv(fact[r] * fact[n - r] % mod) % mod;
}

void solve()
{
    int n;
    cin >> n;

    for (ll i = 1; i <= 2 * n; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }

    ll ans = 2 * C(2 * n - 1, n) % mod;

    ans -= n;
    ans += mod;
    ans %= mod;

    cout << ans << endl;
}

int main()
{
    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}