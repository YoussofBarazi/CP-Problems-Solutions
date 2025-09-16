// wrong
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

bool is_prime(int n)
{
    if (n == 1)
        return false;

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

ll mod = 998244353;
ll inv(int i)
{
    return i <= 1 ? i : mod - (long long)(mod / i) * inv(mod % i) % mod;
}

int n;
vector<int> fact(2 * n + 1, 1);

ll C(ll n, ll r)
{
    return (fact[n] * inv(fact[r] * fact[n - r] % mod)) % mod;
}

void solve()
{
    cin >> n;

    set<int> primes;
    map<int, int> freq;

    for (int i = 1; i <= 2 * n; i++)
    {
        int x;
        cin >> x;

        if (is_prime(x))
            primes.insert(x);

        freq[x]++;
    }

    for (int i = 1; i <= 2 * n; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }

    int num_p = primes.size(), power = n;

    ll ans = C(num_p, n);

    for (auto x : freq)
    {
        if (x.S > 1)
        {
            ans += fact[power] * inv(fact[x.S] - 1) % mod;
            ans %= mod;
        }
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