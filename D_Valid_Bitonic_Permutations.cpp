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

const int N = 110;

int n, i, j, x, y, mod = 1e9 + 7;
ll mem[N][N][N];

ll dp(int l, int r, int t)
{
    if (t == n && (l == 1 || l == n))
        return 0;

    if (l == i && r == j && t != x && t != y)
        return 0;

    if (t == n && l == r)
        return 1;

    ll &ret = mem[l][r][t];

    if (ret != -1)
        return ret;

    ret = 0;

    if (l == i)
    {
        if (t < x && ((t == y && j == r) || t != y))
            ret = dp(l, r - 1, t + 1);
        else if (t == x)
            ret = dp(l + 1, r, t + 1);
    }
    else if (l == j)
    {
        if (t < y)
            ret = dp(l, r - 1, t + 1);
        else if (t == y)
            ret = dp(l + 1, r, t + 1);
    }
    else if (r == i)
    {
        if (t < x)
            ret = dp(l + 1, r, t + 1);
        else if (t == x)
            ret = dp(l, r - 1, t + 1);
    }
    else if (r == j)
    {
        if (t < y && ((t == x && i == l) || t != x))
            ret = dp(l + 1, r, t + 1);
        else if (t == y)
            ret = dp(l, r - 1, t + 1);
    }
    else if (t != x && t != y)
    {
        ret = dp(l + 1, r, t + 1) + dp(l, r - 1, t + 1);
    }

    return ret % mod;
}

void solve()
{
    cin >> n >> i >> j >> x >> y;

    memset(mem, -1, sizeof mem);

    cout << dp(1, n, 1) << endl;
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