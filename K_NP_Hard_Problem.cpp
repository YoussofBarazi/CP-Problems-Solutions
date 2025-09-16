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
vector <bool> vis(N , false);
vector <int> col(N , -1);

void dfs(int u)
{
    vis[u] = true;

    if (col[u] == -1)
        col[u] = 1;

    for (int v : adj[u])
    {
        if (!vis[v])
        {
            col[v] = !col[u];
            dfs(v);
        }
    }
}

void solve()
{
    int n , m;
    cin >> n >> m;

    vector <pair<int , int>> edges(m);

    for (int i = 0 ; i < m ; i ++)
    {
        int u , v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);

        edges[i] = {u , v};
    }

    for (int i = 1 ; i <= n ; i ++)
        if(!vis[i])
            dfs(i);

    for (auto e : edges)
    {
        if (col[e.F] == col[e.S])
        {
            cout << -1 << endl;
            return ;
        }
    }

    vector <int> ans;
    for (int i = 1 ; i <= n ; i ++)
    {
        if (col[i] == 0)
            ans.pb(i);
    }

    cout << ans.size() << endl;

    for (int x : ans)
        cout << x << " ";
    cout << endl;

    ans.clear();

    for (int i = 1 ; i <= n ; i ++)
    {
        if (col[i] == 1)
            ans.pb(i);
    }

    cout << ans.size() << endl;

    for (int x : ans)
        cout << x << " ";
    cout << endl;
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

void IO(string name = "") {

	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}

}