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
#define Sort(a) sort(a.begin(), a.end())
#define Rsort(a) sort(a.rbegin(), a.rend())
#define UB(a, t) upper_bound(a.begin(), a.end(), t) - a.begin()
#define LB(a, t) lower_bound(a.begin(), a.end(), t) - a.begin()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

vector <int> primes;
bool isprime[N];

void getPrimes (int n)
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

void solve()
{
    getPrimes(1e5 + 100);
    int n , m;
    cin >> n >> m;

    vi a[n];
    for (size_t i = 0; i < n; i++)
    {
        a[i].resize(m);
        for (size_t j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    ll ans = 2e9;
    for (size_t i = 0; i < n; i++)
    {
        ll tmp = 0;
        for (size_t j = 0; j < m; j++)
        {
            int ind = LB(primes , a[i][j]);
            tmp += primes[ind] - a[i][j];    
        }
        ans = min(tmp , ans);
    }
    
    for (size_t j = 0; j < m; j++)
    {
        ll tmp = 0;
        for (size_t i = 0; i < n; i++)
        {
            int ind = LB(primes , a[i][j]);
            tmp += primes[ind] - a[i][j];
        }
        ans = min(ans , tmp);
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