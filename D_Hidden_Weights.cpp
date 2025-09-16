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
vector <ll> val(N, 0);
vector <bool> vis(N , false);

void dfs(int u) {
    vis[u] = true;

    for (auto [v, w] : adj[u]) {
        if (vis[v]) {
            continue;
        }

        val[v] = val[u] + w;
        dfs(v);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    while (m --) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, -w});
    }

    for (int i = 1; i <= n; i ++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    for (int i = 1; i <= n ; i ++) {
        cout << val[i] << " ";
    } cout << endl;
}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}