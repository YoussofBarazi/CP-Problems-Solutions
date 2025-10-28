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
vector <int> s;

int mx = 0 , endpoint = 0;

void dfs(int u , int len)
{
    vis[u] = true;

    for (int v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v , len + 1);
        }
    }

    if (len > mx)
        mx = len , endpoint = u;
}

void solve()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 0 << endl;
        return ;
    }

    for (int i = 0 ; i < n ; i ++)
    {
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1 , 0);

    sort(allr(s));

    mx = 0;
    for (int i = 1 ; i <= n ; i ++)
        vis[i] = false;

    dfs(endpoint , 0);

    cout << mx << endl;
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