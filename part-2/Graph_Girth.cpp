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

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 2509;

vector <int> adj[N];
vector <int> dist(N , 1e9);

int ans = N;

void BFS(int u)
{
    queue <int> q;
    q.push(u);
    dist[u] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (dist[v] != 1e9)
            {
                if (dist[u] <= dist[v])
                    ans = min(ans , dist[u] + dist[v] + 1);
            }
            else 
                q.push(v) , dist[v] = dist[u] + 1;
        }
    }
}

void solve()
{
    int n , m;
    cin >> n >> m;

    while (m --)
    {
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1 ; i <= n ; i ++)
    {
        dist.assign(n + 1 , 1e9);
        BFS(i);
    }

    if (ans == N)
        cout << -1 << endl;
    else
        cout << ans << endl;
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