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

ll k;

bool ok(ll mid)
{
    ll diameter = mid;
    ll x = mid;
    ll y = 0;

    ll ans = 1;
    while (y < mid)
    {
        ans += x * 4;
        y++;
        diameter = ceil(sqrt(y * y + x * x));
        while (diameter > mid)
        {
            x--;
            diameter = ceil(sqrt(y * y + x * x));
        }
    }

    return ans >= k;
}

void solve()
{
    cin >> k;

    ll l = 1, r = 1e5;

    while (l < r)
    {
        ll mid = l + (r - l) / 2;

        if (ok(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << r << endl;
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