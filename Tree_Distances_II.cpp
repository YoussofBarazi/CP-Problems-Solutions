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
vector <int> s(N , 0);
vector <ll> ans(N , 0);

void dfs(int u , int p , int d)
{
    s[u] = 1;
    ans[1] += d;

    for (auto v : adj[u])
    {        
        if(p != v)
            dfs(v , u , d + 1) , s[u] += s[v];
    }
}

int n;

void dfs2(int u , int p)
{
    for (auto v : adj[u])
    {
        if (p == v)
            continue;

        ans[v] = ans[u] + n - 2 * s[v];   
        dfs2(v , u);
    }
}

void solve()
{
    cin >> n;

    for (int i = 1 ; i < n ; i ++)
    {
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1 , 0 , 0);
    dfs2(1 , 0);

    for (int i = 1 ; i <= n ; i ++)
        cout << ans[i] << " " ;
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