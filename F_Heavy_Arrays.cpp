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

const int N = 200009 , mod = 1e9 + 7;

ll fact[N];

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

ll inv(ll y, ll mod)
{
    return POW_M(y, mod - 2, mod);
}

ll C(int n , int r) {
    return fact[n] * inv(fact[r] * fact[n - r] % mod , mod) % mod;
}

void solve()
{
    int n;
    cin >> n;

    fact[0] = 1;
    for (int i = 1 ; i <= n ; i ++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    
    ll ans = POW_M(2 , n , mod);

    for (int i = 1 ; i <= n ; i += 2) {
        int RBS = C(i - 1 , i / 2) * inv(i / 2 + 1 , mod) % mod; 
        ans -= RBS * POW_M(2 , n - i , mod) % mod;
        
        if (ans < 0) ans += mod;
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