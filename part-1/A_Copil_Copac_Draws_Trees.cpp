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

vector<int> dp, id;
vector<vector<pair<int, int>>> adj;

void dfs(int u)
{
    for (auto x : adj[u])
    {
        if (dp[x.F] == 0)
        {
            dp[x.F] = dp[u] + (x.S <= id[u]);
            id[x.F] = x.S;
            dfs(x.F);
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    dp = vector(n + 1, 0), id = vector(n + 1, 0);
    adj.clear();
    adj.resize(n + 1);

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }

    dp[1] = 1;
    dfs(1);

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);

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