#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define oo INT_MAX
#define OO LONG_MAX
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

vector<bool> visited;
vector<vector<pair<int, int>>> adj;
vector<int> must;
vector<int> cnt;

void DFS(int v)
{

    visited[v] = true;

    // Recur for all the vertices adjacent
    // to this vertex
    cnt[v]++;
    for (int i = 0; i < adj[v].size(); ++i)
    {
        if (!visited[adj[v][i].F])
            DFS(adj[v][i].F);
        else
            cnt[adj[v][i].F]++;
    }
}

void solve()
{
    int n;
    cin >> n;

    visited.resize(n + 1, false);
    adj.resize(n + 1);
    must.resize(n + 1);
    cnt.resize(n + 1, 0);

    for (size_t i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        must[v] = i;
        adj[u].pb({v, i});
    }
    DFS(1);

    sort(all(cnt));

    cout << cnt[n] + 1 << endl;

    adj.clear();
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