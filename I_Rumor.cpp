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

void dfs(int u)
{
    vis[u] = true;

    for (int v : adj[u])
    {
        if (!vis[v])
            dfs(v);
    }
}

void solve()
{
    int n , m;
    cin >> n >> m;

    vector < pair < ll , int > > a(n);

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> a[i].F;

        a[i].S = i + 1;
    }

    for (int i = 0 ; i < m ; i ++)
    {
        int u , v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    sort(all(a));

    ll ans = 0;

    for (auto x : a)
    {
        if (!vis[x.S])
        {
            ans += x.F ;
            dfs(x.S);
        }
    }

    cout << ans << endl;
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