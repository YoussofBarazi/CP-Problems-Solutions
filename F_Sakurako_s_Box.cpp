#include <bits/stdc++.h>

#define F first
#define S second
#define ll long long
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

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

ll inv(ll y)
{
    return POW_M(y, mod - 2);
}

void solve()
{
    ll n;
    cin >> n;

    vector <int> a(n);
    vector <ll> sum(n);
    for (int &i : a)
        cin >> i;

    sum[0] = a[0];

    for (int i = 1 ; i < n ; i ++)
        sum[i] = (sum[i - 1] + a[i]) % mod;

    ll ans = 0;
    ll pairs = (n - 1) * n % mod * inv(2) % mod;
    ll t1 = inv(pairs);
    
    for (ll i = 1 ; i < n ; i ++)
    {
        ll t2 = (sum[i - 1] * a[i]) % mod;
        ans += t1 * t2 % mod;
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