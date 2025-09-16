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

// const int N = 1e7 + 1;
ll m = 1e9 + 7;
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
    int a, b, n;
    cin >> a >> b >> n;

    vl fact(n + 1, 1);
    for (ll i = 1; i < n + 1; i++)
    {
        fact[i] = (fact[i - 1] * i) % m;
    }

    ll ans = 0;
    for (ll i = 0; i <= n; i++)
    {
        int sum = a * i + b * (n - i);
        bool good = true;

        while (sum > 0)
            good &= (a == sum % 10) || (b == sum % 10), sum /= 10;

        if (good)
            ans += fact[n] * inv((fact[n - i] * fact[i]) % m, m) % m;
        ans %= m;
    }

    cout << ans << endl;
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