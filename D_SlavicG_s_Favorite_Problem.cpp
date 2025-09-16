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

vector < pair < int , int > > adj[N];
bool vis[N];
int n , a , b;

void dfs(int u , vector <int> &XOR)
{
    vis[u] = true;

    for (auto x : adj[u])
    {
        if (!vis[x.F] && x.F != b)
        {
            XOR[x.F] = XOR[u] ^ x.S;
            dfs(x.F , XOR);
        }
    }
}

void solve()
{
    cin >> n >> a >> b;

    set < int > exit_ways;

    for (int i = 0 ; i <= n ; i ++)
    {
        adj[i].clear();
        vis[i] = false;
    }

    for (int i = 1 ; i < n ; i ++)
    {
        int u , v , w;
        cin >> u >> v >> w; 

        adj[u].pb({v , w});
        adj[v].pb({u , w});
    }

    vector < int > XOR_from_a(N , 0);
    vector < int > XOR_from_b(N , 0);

    dfs(a , XOR_from_a);

    for (int i = 1 ; i <= n ; i ++)
    {
        if (vis[i])
        {
            exit_ways.insert(XOR_from_a[i]);
            //cout << "( " << i << " , " << XOR_from_a[i] << " ) .. ";
        }
    }
    
    //cout << "finish" << endl;
    
    for (int i = 0 ; i <= n ; i ++) vis[i] = false;

    dfs(b , XOR_from_b);

    bool ok = false;

    for (int i = 1 ; i <= n ; i ++)
    {
        if (i != b && vis[i] && exit_ways.find(XOR_from_b[i]) != exit_ways.end())
            ok = true;

        // if (i != b && vis[i] && exit_ways.find(XOR_from_b[i]) != exit_ways.end())
        //     cout << "( " << i << " , " << XOR_from_b[i] << " ) .. ";
    }

    if (ok)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    cin >> t;

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
