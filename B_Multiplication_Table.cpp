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

ll n, k;

bool ok(ll m)
{
    ll s = 0;
    for (ll i = 1; i <= n; i++)
    {
        s += min(n, m / i);
    }

    return s >= k;
}

void solve()
{
    scanf("%lld %lld", &n, &k);

    ll l = 1, r = n * n;

    while (l < r)
    {
        ll m = l + (r - l) / 2;

        if (ok(m))
            r = m;
        else
            l = m + 1;
    }

    printf("%lld\n", r);
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