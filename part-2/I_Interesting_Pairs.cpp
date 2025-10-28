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

int primes;

void solve()
{
    int r, l, k;
    cin >> l >> r >> k;

    ll ans = 0;
    for (ll i = 1; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            ll x, y;
            if (gcd(k / i, i) == 1)
            {
                x = (l + i - 1) / i;
                y = r / (k / i);

                ans += max(y - x + 1, 0ll);
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}