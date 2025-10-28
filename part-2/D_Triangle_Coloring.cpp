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

ll mod = 998244353;
vector<ll> fact(4e5 + 7, 1);

int inv(int i)
{
    return i <= 1 ? i : mod - (long long)(mod / i) * inv(mod % i) % mod;
}

ll C(int n, int r)
{
    return fact[n] * inv(fact[r] * fact[n - r] % mod) % mod;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;

    ll ans = 1;
    for (int i = 0; i < n; i += 3)
    {
        map<int, ll> freq;

        freq[a[i]]++;
        freq[a[i + 1]]++;
        freq[a[i + 2]]++;

        ans *= freq[min({a[i], a[i + 1], a[i + 2]})];
        ans %= mod;
    }

    ans *= C(n / 3, n / 6);
    ans %= mod;

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