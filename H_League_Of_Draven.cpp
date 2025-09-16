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

void solve()
{
    int n;
    cin >> n;   

    vi a(1e5 + 1 , 0);
    for (size_t i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        a[x] ++;
    }
    
    ll ans = 0;
    for (size_t i = 0; i < 1e5 + 1; i++)
    {
        if (a[i] > 0)
        {
            ans += POW_M(2 , a[i] , 1e9 + 7) - 1;
            ans %= int(1e9 + 7);
        }
    }
    cout << ans << endl;
}

int main()
{
    IOS;

    int t = 1;
    //cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}