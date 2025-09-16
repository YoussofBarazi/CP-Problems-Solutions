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
vector <int> best_path;
vector <bool> vis;
set <int> path;

int dfs(int u) {
    vis[u] = true;
    int mx_dist = 0;
    
    for (auto v : adj[u]) {
        if (vis[v] || path.count(v)) continue;
        mx_dist = max(mx_dist , dfs(v) + 1);
    }

    return best_path[u] = mx_dist;
}

bool DFS(int u) {
    if (u == 1) {
        return true;
    }

    vis[u] = true;
    for (auto v : adj[u]) {
        if (vis[v]) continue;
        if (DFS(v)) {
            path.insert(v);
            return true;
        }
    }

    return false;
}

int n;

struct SegmentTree {
    #define lc (id << 1)
    #define rc (lc | 1)
    #define mid ((l + r) >> 1)

    vector <int> seg;

    SegmentTree () {
        seg.assign(n << 2 + n , 0);
    }

    void update(int ndx , int val , int id = 1 , int l = 1 , int r = n) {
        if (l == r)
        {
            seg[id] = val;
            return ;
        }

        if (ndx <= mid)
            update(ndx , val , lc , l , mid);
        else 
            update(ndx , val , rc , mid + 1 , r);

        seg[id] = max(seg[lc] , seg[rc]);
    }
};

void solve()
{
    cin >> n;

    for (int i = 0 ; i <= n ; i ++) {
        adj[i].clear();
    }
    vis.assign(n + 1 , false);
    best_path.assign(n + 1 , 0);
    path.clear();

    for (int i = 0 ; i < n - 1 ; i ++) {
        int a , b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int a , b;
    cin >> a >> b;

    a = 1;

    DFS(b);
    path.insert(b);

    for (auto p : path)
        dfs(p);

    int u = b;
    int d = 0;

    vis.assign(n + 1 , false);
    SegmentTree st;

    while (u != 1) {
        st.update(u , best_path[u] + d);
        vis[u] = true;

        for (auto v : adj[u]) {
            if (path.count(v) && !vis[v]) {
                u = v;
                break;
            }
        }

        d ++;
    }

    u = a , d = 0;
    vis.assign(n + 1 , false);

    while (d < (path.size() + 1) / 2) {    
        vis[u] = true;
        st.update(u , 0);
        if (best_path[u] + d > st.seg[1]) {
            cout << "Alice" << endl;
            return ;
        } 

        for (auto v : adj[u]) {
            if (path.count(v) && !vis[v]) {
                u = v;
                break;
            }
        }

        d ++;
    }

    cout << "Bob" << endl;
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