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

vector<vector<int>> adj(N);
vector<bool> visited(N);

void dfs(int u) 
{
	if (visited[u]) { return; }

	visited[u] = true;

	for (int v : adj[u]) { dfs(v); }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector <int> ans;

    for (int i = 1 ; i <= n ; i ++)
    {
        if (!visited[i])
        {
            dfs(i);
            ans.pb(i);
        }
    }

    cout << ans.size() - 1 << endl;
    for (int i = 1 ; i < ans.size() ; i ++)
        cout << ans[i - 1] << " " << ans[i] << endl;
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