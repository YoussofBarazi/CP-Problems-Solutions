#include <bits/stdc++.h>

#define F first
#define S second
#define ll long long
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 200009;

int sz[N];
vector <int> adj[N];
vector<bool> visited;
vector<int> tin, low;
vector<pii> bridges;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
            {
                bridges.push_back({v , to});
            }
        }
    }
}

void find_bridges(int n) {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

int DFS(int u)
{
    visited[u] = true;
    int cnt = 1;

    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            cnt += DFS(v);
        }
    }

    return sz[u] = cnt;
}

void solve()
{
    int n , m;
    cin >> n >> m;

    for (int i = 0 ; i < m ; i ++)
    {
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    find_bridges(n + 1);

    visited.assign(n + 1 , false);

    DFS(1);

    ll t = 1ll * n * (n - 1) / 2 , ans = t;

    for (auto b : bridges)
    {
        int cnt1 = n - sz[b.S] , cnt2 = sz[b.S];
        ans = min(ans , 1ll * cnt1 * (cnt1 - 1) / 2 + 1ll * cnt2 * (cnt2 - 1) / 2);
    }

    cout << ans << endl;

    bridges.clear();
    for (int i = 0 ; i <= n ; i ++)
        adj[i].clear();
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