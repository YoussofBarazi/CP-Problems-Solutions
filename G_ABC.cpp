// not completed
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
ll mod = 1e9 + 7;

vl fact(1e5 + 1, 1);

long long MOD(long long x, long long mod)
{
    return (x % mod + mod) % mod;
}

long long POW_M(long long x, long long y, long long mod)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return MOD(x, mod);

    long long ans = POW_M(x, y / 2, mod);

    if (y & 1)
        return MOD(MOD(ans * ans, mod) * x, mod);
    return MOD(ans * ans, mod);
}

long long inv(long long y, long long mod)
{
    return POW_M(y, mod - 2, mod);
}

void get()
{
    for (ll i = 1; i < 1e5 + 1; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }
}

ll C(ll n, ll r)
{
    return fact[n] * inv(fact[r] * fact[n - r] % mod, mod) % mod;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    if (k % 2)
    {
        cout << 0 << endl;
        return;
    }

    ll ans = C(k, k / 2);

    ans += ans * POW_M(2, k / 2, mod);

    cout << ans << endl;
}

int main()
{
    IOS;
    get();
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}