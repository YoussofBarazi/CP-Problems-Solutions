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

vector<ll> fact(1e6 + 1, 1);

ll C(ll n, ll r)
{
    return fact[n] * inv(fact[r] * fact[n - r] % mod) % mod;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;

    ll ans = 0;
    for (int ones = 0; ones <= n; ones++)
    {
        ans += C(n, ones);
        ans %= mod;
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