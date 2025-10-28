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

vector<int> primes;
bool isprime[N];

void sieve(int n)
{
    for (size_t i = 0; i <= n; i++)
    {
        isprime[i] = true;
    }

    for (size_t i = 2; i <= n; i++)
    {
        if (isprime[i])
        {
            for (size_t j = i * 2; j <= n; j += i)
            {
                isprime[j] = false;
            }
            primes.pb(i);
        }
    }
}

map<int, bool> b;

int calc(int x)
{
    int ans = 0;

    for (int p : primes)
    {
        if (p > x)
            break;

        while (x % p == 0)
        {
            ans += (b[p]) ? -1 : 1;
            x /= p;
        }
    }

    if (x > 1)
        ans += (b[x]) ? -1 : 1;

    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;

        b[x] = true;
    }

    sieve(32000);

    vector<int> GCD(n + 1, 0);
    for (int i = 1; i <= n; i++)
        GCD[i] = gcd(GCD[i - 1], a[i]);

    int div = 1, res = 0;
    for (int i = n; i > 0; i--)
    {
        if (calc(GCD[i] / div) < 0)
            div *= (GCD[i] / div);

        res += calc(a[i] / div);
    }

    cout << res << endl;
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