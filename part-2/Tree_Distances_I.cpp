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
int mx = 0 , ep = 0;

int dist[2][N];

void dfs(int u , int len , int i)
{
    vis[u] = true;

    dist[i][u] = max(dist[i][u] , len);

    for (auto v : adj[u])
    {
        if (!vis[v])
            dfs(v , len + 1 , i);
    }

    if (mx < len)
        mx = len , ep = u;
}


void solve()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    for (int i = 1 ; i < n ; i ++)
    {
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1 , 0 , 0);
    
    int n1 = ep;
    
    vis.assign(n + 1 , false) , mx = 0 , ep = 0;
    dfs(n1 , 0 , 0);

    int n2 = ep;

    vis.assign(n + 1 , false);
    dfs(n2 , 0 , 1);

    for (int i = 1 ; i <= n ; i ++)
        cout << max(dist[1][i] , dist[0][i]) << " ";
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