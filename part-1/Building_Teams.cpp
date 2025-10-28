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
vector <int> color(N , 0);

void dfs(int u , int col)
{
    vis[u] = true;
    color[u] = col;

    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v , abs(col - 3));
        }
    }
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
        if (!vis[i])
            dfs(i , 1);

    for (int u = 1 ; u <= n ; u ++)
    {
        for (auto v : adj[u])
            if (color[u] == color[v])
            {
                cout << "IMPOSSIBLE" << endl;
            }
    }

    for (int i = 1 ; i <= n ; i ++)
        cout << color[i] << " ";

    cout << endl;
}

int main()
{
    IOS;

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}