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

int inv(int i)
{
    return i <= 1 ? i : mod - (long long)(mod / i) * inv(mod % i) % mod;
}

vector<ll> fact(4e5 + 1, 1);

void O_O()
{
    for (ll i = 1; i < 4e5 + 1; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
}

ll sub(ll a, ll b)
{
    return ((a % mod) - (b % mod) + mod) % mod;
}

ll calc(ll n, ll r)
{
    if (n < r)
        return 0;
    return ((fact[n] * inv(fact[n - r])) % mod * inv(fact[r]) % mod) % mod;
}

void solve()
{
    ll A, B, C, k, c;
    cin >> A >> B >> C >> k >> c;

    if (A + B + c < k || k - c < 2)
    {
        cout << 0 << endl;
        return;
    }

    ll ans1 = calc(C, c);
    k -= c;

    ll s1 = calc(A, k);
    ll s2 = calc(B, k);

    ll ans2 = calc(A + B, k);

    ans2 = sub(ans2, s1);
    ans2 = sub(ans2, s2);

    cout << ans1 * ans2 % mod << endl;
}

int main()
{
    IOS;

    O_O();

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}