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

const int N = 3009;

vector <int> adj[N];
vector <bool> vis(N , false) , closed(N , false); 

int dfs (int u)
{
    vis[u] = true;

    int cnt = 1;
    for (auto v : adj[u])
    {
        if (!closed[v] && !vis[v])
            cnt += dfs(v);
    }

    return cnt;
}

void solve()
{
    int n , m;
    cin >> n >> m;

    set <int> open;
    for (int i = 1 ; i <= n ; i ++)
        open.insert(i);

    for (int i = 0 ; i < m ; i ++)
    {
        int u , v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    if (dfs(1) == n)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;

    while (--n)
    {
        int c ;
        cin >> c;

        vis = vector <bool> (N , false);
        closed[c] = true;
        open.erase(c);

        int u = *open.begin();

        if (dfs(u) == n)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
}

int main()
{
    freopen("closing.in" , "r" , stdin);
    freopen("closing.out" , "w" , stdout);

    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}