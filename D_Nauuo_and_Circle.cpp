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

const int N = 200009;

int mod = 998244353;

int n;
ll ans = 1;
vector<vector<int>> adj(N + 1);
vector<ll> fact(N + 1, 1);

void dfs(int u)
{
    for (auto v : adj[u])
    {
        dfs(v);
    }

    if (u == 1)
        ans *= fact[adj[u].size()];
    else
        ans *= fact[adj[u].size() + 1];
    ans %= mod;
}

void solve()
{
    cin >> n;

    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        indegree[v]++;
    }

    for (ll i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;

    int root;
    for (int i = 1; i <= n; i++)
        if (!indegree[i] && adj[i].size())
            root = i;

    dfs(root);

    cout << ans * n % mod << endl;
}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}