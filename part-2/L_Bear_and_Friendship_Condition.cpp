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

int dfs(int u , int &cnt)
{
    vis[u] = true;

    int ans = adj[u].size();

    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            cnt ++;
            ans += dfs(v , cnt);
        }
    }

    return ans;
}

void solve()
{
    int n , m;
    cin >> n >> m;

    for (int i = 0 ; i < m ; i ++)
    {
        int u , v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1 ; i <= n ; i ++)
    {
        if (!vis[i])
        {
            int nodes = 1 , edges = dfs(i , nodes); 

            if (1ll * nodes * (nodes - 1) != edges)
            {
                cout << "NO" << endl;
                return ;
            }
        }
    }

    cout << "YES" << endl;
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