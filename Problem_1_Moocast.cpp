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

const int N = 1009;

int n;
pii a[N];
vector <int> adj[N];
vector <bool> vis(N , false);
double dist[N][N];

int dfs (int u)
{
    vis[u] = true;

    int cnt = 1;
    for (auto v : adj[u])
    {
        if (!vis[v])
            cnt += dfs(v);
    }

    return cnt;
}

bool ok(int x)
{
    for (int i = 0 ; i < n ; i ++)
        adj[i].clear() , vis[i] = false;

    double static_dist = sqrt(x);

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = i + 1 ; j < n ; j ++)
        {
            if (static_dist - dist[i][j] > 0)
                adj[i].pb(j) , adj[j].pb(i);
        }
    }

    return dfs(0) == n;
}

void solve()
{
    cin >> n ;

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> a[i].F >> a[i].S;
    }

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = 0 ; j < n ; j ++)
        {
            dist[i][j] = sqrt((a[i].F - a[j].F) * (a[i].F - a[j].F) + (a[i].S - a[j].S) * (a[i].S - a[j].S));
        }
    }

    ll l = 0 , r = 2e9;

    while (l + 1 < r)
    {
        int mid = (l + r) / 2;

        if (ok(mid))
            r = mid;
        else 
            l = mid;
    }

    cout << l << endl;
}

int main()
{
    freopen("moocast.in" , "r" , stdin);
    freopen("moocast.out" , "w" , stdout);

    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}