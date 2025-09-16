#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 100009, M = 101;

int n, m, x[N];
ll dp[N][M];
bool vis[N][M];
int mod = 1e9 + 7;

ll func(int cur, int last)
{
    if (cur == n)
        return 1;
    if (x[cur] && abs(x[cur] - last) > 1)
        return 0;

    ll &ret = dp[cur][last];

    if (vis[cur][last])
        return ret;

    vis[cur][last] = true;

    if (!x[cur])
    {   
        ret = func(cur + 1, last);

        if (last - 1 > 0)
            ret += func(cur + 1, last - 1);
        if (last + 1 <= m)
            ret += func(cur + 1, last + 1);
    }
    else
        ret = func(cur + 1, x[cur]);

    ret %= mod;

    return ret;
}

void solve()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> x[i];

    ll ans = 0;

    if (x[0] == 0)
        for (int i = 1; i <= m; i++)
            ans += func(1, i);
    else
        ans = func(1, x[0]);

    cout << ans % mod << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "")
{

    cin.tie(0)->sync_with_stdio(0);
    if (name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}