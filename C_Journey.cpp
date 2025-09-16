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

const int N = 100009;

vector <int> adj[N];
vector <bool> vis(N , false);

double dfs(int u , int len , double prob)
{
    vis[u] = true;
    int cnt = 0;

    for (int v : adj[u])
    {
        if (!vis[v])
            cnt ++;        
    }

    double ans = 0.0;

    if (cnt == 0)
        ans = prob * len;

    for (int v : adj[u])
    {
        if (!vis[v])
            ans += dfs(v , len + 1 , prob / cnt);        
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1 ; i < n ; i ++)
    {
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << fixed << setprecision(15);
    cout << dfs(1 , 0 , 1) << endl;
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