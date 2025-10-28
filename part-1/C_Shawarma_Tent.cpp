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
    int n, x, y;
    cin >> n >> x >> y;

    vector<pi> a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i].F >> a[i].S;
    }

    int mx = 0;
    pi ans;

    if (x > 0)
    {
        int cnt = 0;
        for (size_t i = 0; i < n; i++)
        {
            if (a[i].F <= x - 1)
                cnt++;
        }
        if (cnt > mx)
        {
            mx = cnt;
            ans = {x - 1, y};
        }
    }
    if (y > 0)
    {
        int cnt = 0;
        for (size_t i = 0; i < n; i++)
        {
            if (a[i].S <= y - 1)
                cnt++;
        }
        if (cnt > mx)
        {
            mx = cnt;
            ans = {x , y - 1};
        }
    }

    int cnt = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (a[i].F >= x + 1)
        {
            cnt++;
        }
    }
    if (cnt > mx)
    {
        mx = cnt;
        ans = {x + 1, y};
    }
    cnt = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (a[i].S >= y + 1)
        {
            cnt++;
        }
    }
    if (cnt > mx)
    {
        mx = cnt;
        ans = {x , y + 1};
    }

    cout << mx << endl << ans.F << " " << ans.S << endl;
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