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

vector <vector<int>> adj(N);
vector <vector<int>> adj_rev(N);
vector <bool> vis(N);
vector <int> color(N) , ts;

void DFS(int u , vector <int> &output , vector <vector<int>> &adj) {
    vis[u] = true;

    for (auto v : adj[u]) {
        if (vis[v]) continue;
        DFS(v , output, adj);
    }

    output.push_back(u);
}

void solve()
{
    int n , m;
    cin >> n >> m;

    while (m --) {
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }

    for (int i = 1 ; i <= n ; i ++) {
        if (!vis[i]) DFS(i , ts , adj);
    }
    
    vis.assign(n + 1 , false);
    reverse(all(ts));
    int c = 0;

    for (auto u : ts) {
        vector <int> comp;
        if (!vis[u]) DFS(u , comp , adj_rev) , ++ c;
        for (auto v : comp) {
            color[v] = c;
        }
    }

    cout << c << endl;
    for (int i = 1 ; i <= n ; i ++) {
        cout << color[i] << " ";
    }
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