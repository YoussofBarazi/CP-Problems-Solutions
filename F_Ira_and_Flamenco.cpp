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
    int n, m;
    cin >> n >> m;

    vector<pl> a;
    map<ll, ll> cnt;
    for (size_t i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        cnt[x]++;
    }

    for (auto x : cnt)
        a.pb({x});

    for (size_t i = 1; i < a.size(); i++)
    {
        a[i].S *= a[i - 1].S;
        a[i].S %= mod;
    }

    ll ans = 0;
    for (size_t i = m - 1; i < a.size(); i++)
    {
        if (a[i].F - a[i - m + 1].F == m - 1)
        {
            if (i == m - 1)
                ans += a[m - 1].S;
            else
                ans += a[i].S * inv(a[i - m].S, mod) % mod;

            ans %= mod;
        }
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