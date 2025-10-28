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

const int N = 200009;

vector<int> adj[N];
vector<bool> vis(N, false);
vector<int> color(N, 0);
int col1, col2;

void dfs(int u, int col)
{
    vis[u] = true;
    color[u] = col;
    col1 += col == 1;
    col2 += col == 2;

    for (auto v : adj[u])
        if (!vis[v])
            dfs(v, abs(col - 3));
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, 1);
    
    ll ans = col1 * 1ll * col2 - n + 1;

    cout << max(ans , 0ll) << endl;
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