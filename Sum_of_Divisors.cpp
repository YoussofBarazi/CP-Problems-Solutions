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
ll inv = 5e8 + 4;
ll n;

ll mul(ll x, ll y)
{
    return (x % mod * (y % mod)) % mod;
}

ll add(ll x, ll y)
{
    return ((x % mod) + (y % mod)) % mod;
}

ll calc(ll x)
{
    ll left = n / (x + 1);
    ll right = n / x;

    ll sumL = mul(mul(left + 1, left), inv);
    ll sumR = mul(mul(1 + right, right), inv);

    return mul(sumR - sumL, x);
}

void solve()
{
    cin >> n;

    ll ans = 0;

    for (ll i = 1; i * i <= n; i++)
    {
        ans = add(ans, calc(i));
        if (n / i != i)
            ans = add(ans, calc(n / i));
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