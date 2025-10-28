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

const int N = 10009;

ll mod = 998244353;

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

ll mem[N][N];
int n, x;
int T[N];
ll inverse;

ll dp(int i, int t, ll p)
{
    if (t <= x && t + T[0] > x)
        return p * inverse % mod;

    if (i == n || t > x)
        return 0;

    ll &ret = mem[i][t];

    if (ret != -1)
        return ret;

    ret = dp(i, t + T[i], p * inverse % mod) + dp(i + 1, t, p);

    return ret % mod;
}

void solve()
{
    cin >> n >> x;

    for (int i = 0; i < n; i++)
        cin >> T[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= x; j++)
            mem[i][j] = -1;

    inverse = inv(n);

    cout << dp(0, 0, 1) << endl;
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