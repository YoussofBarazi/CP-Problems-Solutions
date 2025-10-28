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
int c[N];
vector <set<int>> node(N);
int ans[N];

void dfs(int u , int p) {
    node[u].insert(c[u]);

    for (int v : adj[u]) {
        if (v == p) continue;

        dfs(v , u);

        if (node[u].size() < node[v].size()) swap(node[u] , node[v]);

        for (auto x : node[v]) {
            node[u].insert(x);
        }
    }

    ans[u] = node[u].size();
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1 ; i <= n ; i ++) {
        cin >> c[i];
    }

    for (int i = 0 ; i < n - 1 ; i ++) {
        int a , b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1 , 0);

    for (int i = 1 ; i <= n ; i ++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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