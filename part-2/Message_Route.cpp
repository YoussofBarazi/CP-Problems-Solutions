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

const int N = 100009;

vector <int> adj[N];
vector <int> dist(N , 1e9);
vector <int> parent(N , 0);
vector <bool> vis(N , false);

void BFS(int u)
{
    queue <int> q;
    q.push(u);
    dist[u] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (vis[u])
            continue;

        vis[u] = true;

        for (int v : adj[u])
        {   
            if (!vis[v])
                q.push(v);
            
            if (dist[u] + 1 < dist[v])
                dist[v] = dist[u] + 1 , parent[v] = u;
        }
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
    
    BFS(1);

    vector <int> path;

    int u = n;

    while (u != 0)
    {
        path.push_back(u);
        u = parent[u];
    }

    reverse(all(path));

    if (path.front() != 1)
    {
        cout << "IMPOSSIBLE" << endl;
        return ;
    }

    cout << path.size() << endl;

    for (auto n : path)
        cout << n << " ";
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "") {

	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}

}