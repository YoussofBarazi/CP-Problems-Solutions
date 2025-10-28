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

void solve()
{
    int n, k;
    cin >> n >> k;

    map<vector<pi>, int> m;

    for (size_t i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        vector<pi> v;
        // cout << x << " : " << endl;

        for (int prime = 2; prime * prime <= x; prime++)
        {
            int cnt = 0;
            while (x % prime == 0)
            {
                x /= prime;
                cnt++;
            }

            if (cnt != 0 && cnt % k != 0)
                v.pb({prime, cnt % k});
        }

        if (x > 1 && k != 1)
            v.pb({x, 1});

        /*for (auto x : v)
            cout << x.F << " -> " << x.S << endl;*/
        m[v]++;
    }

    ll ans = 0;

    for (auto z : m)
    {
        vector<pi> v;

        for (size_t i = 0; i < z.F.size(); i++)
        {
            v.pb({z.F[i].F, k - z.F[i].S});
        }

        if (v == z.F)
            ans += (1ll * z.S * (z.S - 1)) / 2;
        else
            ans += 1ll * m[v] * 1ll * z.S;
        m[v] = 0;
        m[z.F] = 0;
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