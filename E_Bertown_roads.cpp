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
vector<bool> visited;
vector<int> tin, low;
int timer , cnt;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
            {
                cnt ++;
            }
        }
    }
}

void find_bridges(int n) {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

set <pii> passed_edges;

void DFS(int u)
{
    if (visited[u])
        return ;
    
    visited[u] = true;

    for (auto v : adj[u])
    {
        if (passed_edges.find({min(u , v) , max(u , v)}) != passed_edges.end())
            continue;

        cout << u << " " << v << endl;
        passed_edges.insert({min(u , v) , max(u , v)});
        DFS(v);
    }
}

void solve()
{
    int n , m;
    cin >> n >> m;

    for (int i = 0 ; i < m ; i ++)
    {
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    find_bridges(n + 1);

    if (cnt > 0)
    {
        cout << "0\n";
        return ;
    }

    visited.assign(n + 1 , false);

    DFS(1);
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