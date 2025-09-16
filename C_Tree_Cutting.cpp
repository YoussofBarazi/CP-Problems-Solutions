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
int res;

int dfs(int u , int x , int p)
{
    int cnt = 1;

    for (auto v : adj[u])
    {
        if (p != v)
            cnt += dfs(v , x , u);
    }

    if (cnt >= x)
    {
        res ++ , cnt = 0;    
    }

    return cnt;
}

int n , k;

bool ok (int x)
{
    res = 0;
    int t = dfs(1 , x , -1);

    return (res > k);
}

void solve()
{
    cin >> n >> k;

    for (int i = 0 ; i < n - 1 ; i ++)
    {
        int u , v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    int l = 0 , r = n;

    while (l + 1 < r)
    {
        int m = (l + r) / 2;

        if (ok(m))
            l = m;
        else 
            r = m;
    }

    cout << l << endl;

    for (int i = 0 ; i <= n ; i ++)
        adj[i].clear();
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