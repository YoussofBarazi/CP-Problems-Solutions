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

vector <int> adj[2][N];
vector <bool> vis(N , false);

int mx = 0 , endpoint = 0;

void dfs(int u , int len , int g)
{
    vis[u] = true;

    for (int v : adj[g][u])
    {
        if (!vis[v])
            dfs(v , len + 1 , g);
    }

    if (mx < len)
        mx = len , endpoint = u;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1 ; i < n ; i ++)
    {
        int u , v;
        cin >> u >> v;

        adj[0][u].push_back(v);
        adj[0][v].push_back(u);
    }

    int m;
    cin >> m;

    for (int i = 1 ; i < m ; i ++)
    {
        int u , v;
        cin >> u >> v;

        adj[1][u].push_back(v);
        adj[1][v].push_back(u);
    }

    dfs(1 , 0 , 0);
    vis.assign(n + 1 , false) , mx = 0;
    if (endpoint) dfs(endpoint , 0 , 0);

    int d1 = mx;

    vis.assign(m + 1 , false) , mx = 0 , endpoint = 0;
    dfs(1 , 0 , 1);
    vis.assign(m + 1 , false) , mx = 0;
    if (endpoint) dfs(endpoint , 0 , 1);

    int d2 = mx;

    cout << max({(d1 + 1) / 2 + (d2 + 1) / 2 + 1 , d1 , d2}) << endl;
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