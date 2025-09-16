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
int cycle_start = -1;

void find_cycle(int u , int par)
{
    vis[u] = true;

    for (int v : adj[u])
    {
        if (v == par)
            continue;
        
        if (!vis[v])
        {
            find_cycle(v , u);
        }
        else 
        {
            if (cycle_start == -1)
                cycle_start = v;
            return;
        }
    }
}

int dfs(int u)
{
    if (u == cycle_start)
        return 0;

    int ans = 1e9;
    vis[u] = true;

    for (int v : adj[u])
    {
        if (!vis[v])
        {
            ans = min(ans , dfs(v) + 1);
        }
    }

    return ans;
}

void init(int n)
{
    for (int i = 0 ; i <= n ; i ++)
    {
        adj[i].clear();
        vis[i] = false;
    }
    cycle_start = -1;
}

void solve()
{
    int n , a , b;
    cin >> n >> a >> b;
    
    init(n);

    for (int i = 0 ; i < n ; i ++)
    {
        int u , v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    find_cycle(b , -1);

    vis.assign(n + 1 , false);

    int dist_from_a = dfs(a);

    vis.assign(n + 1 , false);

    int dist_from_b = dfs(b);

    //cout << cycle_start << " " << dist_from_a << " " << dist_from_b << endl;

    if (dist_from_a > dist_from_b)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    
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