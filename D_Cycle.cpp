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

vector <int> adj[N];
vector <bool> vis(N , false);
bool has_path_to_1[N];
int ans = N;

void dfs(int u = 1 , int cnt = 1) {
    vis[u] = true;

    for (auto v : adj[u]) {
        if (vis[v]) {
            if (v == 1) ans = min(ans , cnt);
            continue;
        }
        if (has_path_to_1[v]) {
            dfs(v , cnt + 1);
        }
    }
}


bool dfs2(int u) {
    bool &x = has_path_to_1[u];
    cout << u << " ";
    if (vis[u]) {
        return x;
    }

    vis[u] = true;

    for (int v : adj[u]) {
        x |= dfs2(v);
    }

    return x;
}

void solve()
{
    int n , m;
    cin >> n >> m;

    for (int i = 0 ; i < m ; i ++) {
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    vis[1] = has_path_to_1[1] = true;

    for (int i = 1 ; i <= n ; i ++) 
    {    dfs2(i);
        cout << endl << has_path_to_1[i] << endl;
    }

    vis.assign(N , false);
    dfs();

    if (ans == N) ans = -1;

    cout << ans << endl;
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