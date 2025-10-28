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

vl a, levels, ans;
ll n, k, x;

bool ok(ll m)
{
    ans = vector(n, 0ll);
    ll cnt = 0;
    vector<pair<ll, int>> v;

    for (int i = 0; i < n; i++)
    {
        cnt += max(m - levels[i], 0ll);
        ans[i] = max(m - levels[i], 0ll);

        if (m - levels[i] >= 0)
            v.push_back({ans[i] * x + a[i], i});
    }

    sort(all(v));

    for (auto x : v)
    {
        if (cnt < k)
            cnt++, ans[x.S]++;
    }

    return cnt >= k;
}

void solve()
{
    cin >> n >> k >> x;

    a.resize(n);
    levels.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        levels[i] = a[i] / x;
    }

    int l = 0, r = 1e9;

    while (l < r)
    {
        int m = (l + r) / 2;

        if (ok(m))
            r = m;
        else
            l = m + 1;
    }

    ok(l);

    for (auto x : ans)
        cout << x << " ";
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