#include <bits/stdc++.h>

#define F first
#define S second
#define ll long long
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 1009;

vector <vector<pii>> adj(N);
bool vis[N][N];
ll ans[N];
int bike[N];

// 5  2  1  3  3
// 0 10 12 20 22

ll dfs(int u , int b , int par)
{
    vis[u][b] = true;

    for (auto v : adj[u])
    {
        if (par != v.F)
            ans[v.F] = min(ans[v.F] , ans[u] + v.S * bike[b]);       

        if (!vis[v.F][b])
        {
            ans[v.F] = min(ans[v.F] , ans[u] + v.S * bike[b]);       
            dfs(v.F , b , u);
            dfs(v.F , v.F , u);
        }
    }
}

void solve()
{
    int n , m;
    cin >> n >> m;

    for (int i = 0 ; i <= n ; i ++)
    {    
        adj[i].clear() , ans[i] = LLONG_MAX;

        for (int j = 0 ; j <= n ; j ++)
            vis[i][j] = false;
    }

    while (m --)
    {
        int u , v , w;
        cin >> u >> v >> w;

        adj[u].push_back({v , w});
        adj[v].push_back({u , w});
    }

    for (int i = 1 ; i <= n ; i ++)
        cin >> bike[i];

    ans[1] = 0;

    dfs(1 , 1 , 0);

    for (int i = 1 ; i <= n ; i ++)
        cout << ans[i] << " ";
    cout << endl;

}

int main()
{
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}