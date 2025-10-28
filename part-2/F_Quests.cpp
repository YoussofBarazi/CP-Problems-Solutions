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
ll n, c, d;
ll ans = 0;

bool check(ll k, vl &a)
{
    ll res = 0;
    for (ll i = 0; i < n; i++)
    {
        res += (max(d - i, 0ll) / (k + 1)) * a[i];
    }

    return res >= c;
}

void solve()
{
    cin >> n >> c >> d;

    vl a(n);
    int i = 0;

    for (; i < n; i++)
    {
        cin >> a[i];
    }
    Rsort(a);

    for (size_t i = 0; i < min (n , d); i++)
    {
        ans += a[i];
    }
    
    if (a[0] * d < c)
    {
        cout << "Impossible" << endl;
        return;
    }
    if (ans >= c)
    {
        cout << "Infinity" << endl;
        return;
    }
    
    ll l = 0, r = d;
    for (size_t i = 0; i < 100; i++)
    {
        ll m = (l + r) / 2;

        if (check(m, a))
        {
            l = m;
        }
        else
        {
            r = m - 1;
        }
    }

    cout << l << endl;
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