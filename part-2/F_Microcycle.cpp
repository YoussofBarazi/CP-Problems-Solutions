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

vector <int> adj[N];
vector <bool> vis(N);
vector <int> par(N);
int cycle_start = -1;

void dfs(int u , int p)
{
    if (cycle_start != -1)
        return;

    vis[u] = true;

    for (int v : adj[u])
    {
        if (p == v)
            continue;

        if (vis[v])
        {
            cycle_start = v;
        }
        else 
        {
            par[v] = u;
            dfs(v , u);
        }
    }
}

int parent[N], Size[N];

int get(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = get(parent[v]);
}

bool join(int a, int b)
{
    a = get(a);
    b = get(b);

    if (a == b)
        return false;

    if (Size[a] < Size[b])
        swap(a, b);

    parent[b] = a;

    Size[a] += Size[b];

    return true;
}

void solve()
{
    int n , m;
    cin >> n >> m;

    vis.assign(n + 1 , false);
    par.assign(n + 1 , -1);
    cycle_start = -1;
    for (int i = 0 ; i <= n ; i ++)
    {
        adj[i].clear();
        parent[i] = i , Size[i] = 1;
    }

    vector <pair<int  , pii>> edges(m);

    for (int i = 0 ; i < m ; i ++)
    {
        int u , v , c;
        cin >> u >> v >> c;

        edges[i] = {c , {u , v}};
    }

    sort(allr(edges));

    int ans = -1 , u = -1 , v = -1;

    for (auto e : edges)
    {
        if (join(e.S.F , e.S.S))
        {
            adj[e.S.F].pb(e.S.S);
            adj[e.S.S].pb(e.S.F);
        }
        else
        {
            ans = e.F;
            u = e.S.F;
            v = e.S.S;
        }
    }

    adj[u].pb(v);
    adj[v].pb(u);

    dfs(u , -1);

    u = cycle_start;

    vector <int> cycle;

    for ( ; u != -1 ; u = par[u])
        cycle.pb(u);

    cout << ans << " " << cycle.size() << endl;
    for (auto x : cycle)
        cout << x << " ";
    cout << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "") {

	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}

}