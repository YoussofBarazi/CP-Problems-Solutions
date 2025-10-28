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

int mod = 1e9 + 7;
int inv(int i)
{
    return i <= 1 ? i : mod - (long long)(mod / i) * inv(mod % i) % mod;
}

vector<ll> fact(2e6 + 1, 1);

ll C(ll n, ll r)
{
    return fact[n] * inv(fact[n - r] * fact[r] % mod) % mod;
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    for (ll i = 1; i <= n + m - 1; i++)
        fact[i] = fact[i - 1] * i % mod;

    ll ans = C(n + m - 1, n - 1);

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