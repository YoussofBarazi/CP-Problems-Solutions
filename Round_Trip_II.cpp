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

const int N = 200009;

vector <int> adj[N];
vector <int> color(N);
vector <int> parent(N);
int cs = -1;

bool DFS(int u)
{
    color[u] = 1;

    for (auto v : adj[u])
    {
        if (color[v] == 2)
            continue;
        
        parent[v] = u;
        
        if (color[v] == 1)
        {   
            cs = v;
            return true;
        }

        if (DFS(v))
        {
            color[u] = 2;
            return true;
        }
    }

    color[u] = 2;
    return false;
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
    }

    for (int i = 1 ; i <= n ; i ++)
        if (color[i] == 0 && DFS(i))
            break;


    if (cs == -1)
    {
        cout << "IMPOSSIBLE" << endl;
        return ;
    }

    vector <int> cycle = {cs};
    int u = parent[cs];

    // for (int i = 1 ; i <= n ; i ++)
    // {
    //     cout << parent[i] << " ";
    // }
    // cout << endl;

    while (cs != u)
    {
        cycle.push_back(u);
        u = parent[u];
    }

    cycle.push_back(cs);

    reverse(all(cycle));

    cout << cycle.size() << endl;
    for (auto x : cycle)
        cout << x << " ";
    cout << endl;
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