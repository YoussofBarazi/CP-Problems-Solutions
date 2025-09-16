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
int mod = 1e9 + 7;
vl fact(1e6 + 7);

void calc(int n)
{
    fact[0] = fact[1] = 1;

    for (ll i = 2; i < n; i++)
    {
        fact[i] = fact[i - 1] % mod * i;
        fact[i] %= mod;
    }
}

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

// O(log2 y)
long long inv(long long y, long long mod)
{
    return POW_M(y, mod - 2, mod);
}

void solve()
{
    int a, b;
    cin >> a >> b;

    ll ans = fact[a] * inv((fact[b] * fact[a - b]) % mod, mod) % mod;

    cout << ans << endl;
}

int main()
{
    IOS;
    calc(1e6 + 7);
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}