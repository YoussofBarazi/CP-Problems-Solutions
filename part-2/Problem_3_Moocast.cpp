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

struct Cow {
    
    double x , y , p;

    Cow (int xx , int yy , int pp)
    {
        x = xx , y = yy , p = pp;
    }

    bool transmit (Cow c)
    {
        double dist = sqrt((x - c.x) * (x - c.x) + (y - c.y) * (y - c.y));

        return p - dist > 0;
    }
};

vector<int> adj[N];
vector <bool> vis(N , false);

int dfs (int u)
{
    vis[u] = true;

    int cnt = 0;
    for (auto v : adj[u])
        if (!vis[v])
            cnt += 1 + dfs(v);

    return cnt;
}


void solve()
{
    int n;
    cin >> n;

    vector <Cow> a;
    for (int i = 0 ; i < n ; i ++)
    {
        int x , y , p ;
        cin >> x >> y >> p;

        a.pb(Cow(x , y , p));
    }

    int mx = 0;

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = 0 ; j < n ; j ++)
        {
            if (i != j && a[i].transmit(a[j]))
                adj[i].pb(j);
        }
    }

    for (int i = 0 ; i < n ; i ++)
    {
        vis = vector <bool> (N , false);
        mx = max(mx , dfs(i) + 1);
    }

    cout << mx << endl;
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