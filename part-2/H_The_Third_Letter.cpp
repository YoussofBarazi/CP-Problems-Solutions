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

const int N = 200009;

vector <pii> adj[N];
vector <ll> camp(N);
vector <bool> vis(N);

void dfs(int u)
{
    vis[u] = true;

    for (auto v : adj[u])
    {
        if (vis[v.F])
            continue;

        camp[v.F] = camp[u] + v.S;
        dfs(v.F);
    }
}

void solve()
{
    int n , m;
    cin >> n >> m;

    for (int i = 0 ; i <= n ; i ++)
        adj[i].clear() , camp[i] = 0 , vis[i] = false;

    vector <array<int , 3>> conditions;

    for (int i = 0 ; i < m ; i ++)
    {
        int a , b , d;
        cin >> a >> b >> d;

        adj[a].push_back({b , d});
        adj[b].push_back({a , -d});
        conditions.push_back({a , b , d});
    }

    for (int i = 1 ; i <= n ; i ++)
        if (!vis[i]) dfs(i);

    for (auto c : conditions)
    {
        int a = c[0] , b = c[1] , d = c[2];

        if (camp[a] != camp[b] - d)
        {
            cout << "NO" << endl;
            return ;
        }
    }

    cout << "YES" << endl;
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