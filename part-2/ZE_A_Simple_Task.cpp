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

const int N = 20;

bool adj[N][N];
vector <bool> vis(N , false);

bool dfs(int mask , int u , int par)
{
    if (vis[u])
        return true;

    vis[u] = true;

    bool ans = true;

    for (int v = 0 ; v < 19 ; v ++)
        if (mask & (1 << v) && v != par && adj[u][v])
        {
            ans &= dfs(mask , v , u);
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

        u -- , v --;

        adj[u][v] = true;
        adj[v][u] = true;
    }

    for (int mask = 0 ; mask < (1 << 19) ; mask ++)
    {
        for (int i = 0 ; i < n ; i ++)
            vis[i] = false;
    }
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