#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 500009;

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

int a[N];
int n;

void solve()
{
    cin >> n;

    vector<int> freq(51, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        freq[a[i]]++;
    }

    int unique = 0;

    for (int i = 2; i <= 50; i++)
        unique += bool(freq[i]);

    ll ans = 1e18;

    for (int i = 1; i <= (1 << 15) - 1; i++)
    {
        ll res = 1;
        for (int j = 0; j < 15; j++)
        {
            if (i & (1 << j))
            {
                res *= primes[j];
            }
        }

        ll g = 0, cnt = 0;
        for (int i = 2; i <= 50; i++)
        {
            if (freq[i])
            {
                g = gcd(i, res);

                cnt += (g >= 2);
            }
        }

        //cout << res << " " << cnt << " " << unique << endl;

        if (cnt == unique)
            ans = min(ans, res);
    }

    cout << ans << endl;
}

int main()
{
    // IO("name");
    IOS;

    sieve(50);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "")
{

    cin.tie(0)->sync_with_stdio(0);
    if (name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}