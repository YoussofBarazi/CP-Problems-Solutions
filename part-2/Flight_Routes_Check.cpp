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
vector <vector<bool>> vis(2 , vector<bool>(N , false));

void dfs(int u , int t)
{
    vis[t][u] = true;

    for (auto v : adj[t][u])
        if (!vis[t][v])
            dfs(v , t);
}

void solve()
{
    int n , m;
    cin >> n >> m;

    for (int i = 0 ; i < m ; i ++)
    {
        int u , v;
        cin >> u >> v;

        adj[0][u].pb(v);
        adj[1][v].pb(u);
    }

    dfs(1 , 0);

    for (int i = 1 ; i <= n ; i ++)
    {
        if (!vis[0][i])
        {
            cout << "NO" << endl << 1 << " " << i << endl;
            return;
        }
    }

    dfs(1 , 1);

    for (int i = 1 ; i <= n ; i ++)
    {
        if (!vis[1][i])
        {
            cout << "NO" << endl << i << " " << 1 << endl;
            return;
        }
    }

    cout << "YES" << endl;
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