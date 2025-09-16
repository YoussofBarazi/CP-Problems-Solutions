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

const int N = 200009 , MOD = 1e9 + 7;

vector <int> adj[N];
vector <bool> vis(N);
vector <int> ts;

void DFS(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (vis[v]) continue;
        DFS(v);
    }
    ts.push_back(u);
}

void solve()
{
    int n , m;
    cin >> n >> m;

    while (m --) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1 ; i <= n ; i ++) {
        DFS(i);
    }

    vector <int> dp(n + 1 , 0);
    dp[n] = 1;

    for (int i = 0 ; i < n ; i ++) {
        int u = ts[i];
        for (auto v : adj[u]) {
            dp[u] += dp[v];
            dp[u] %= MOD;
        }
    }

    cout << dp[1] << endl;
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