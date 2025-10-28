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

ll m, n;
vector<ll> t, y, z;

bool ok(ll T)
{
    ll ballons = m;

    for (int i = 0; i < n; i++)
    {
        ll x1 = (T / (t[i] * z[i] + y[i])) * z[i];
        ll x2 = T % (t[i] * z[i] + y[i]) / t[i];

        x2 = min(x2, z[i]);

        ballons -= (x1 + x2);
    }

    return ballons <= 0;
}

void solve()
{
    cin >> m >> n;

    t.resize(n), y.resize(n), z.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> z[i] >> y[i];
    }

    ll l = 0, r = 2e10;
    while (l < r)
    {
        ll mid = l + (r - l) / 2;

        if (ok(mid))
            r = mid;
        else
            l = mid + 1;
    }

    ll T = r;

    cout << T << endl;

    for (int i = 0; i < n; i++)
    {
        ll x1 = (T / (t[i] * z[i] + y[i])) * z[i];
        ll x2 = T % (t[i] * z[i] + y[i]) / t[i];

        x2 = min(x2, z[i]);

        cout << min(x1 + x2, max(m, 0ll)) << " ";
        m -= (x1 + x2);
    }
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