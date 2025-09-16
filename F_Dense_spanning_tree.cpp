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

int par[N] , sz[N];

int find(int u)
{
    return par[u] = (u == par[u])? u : find(par[u]);
}

bool join(int u , int v)
{
    u = find(u);
    v = find(v);

    if (u == v)
        return false;

    if (sz[u] < sz[v])
        swap(u , v);

    sz[u] += sz[v];
    par[v] = u;

    return true;
}


void solve()
{
    int n , m;
    cin >> n >> m;

    vector <array<int , 3>> edge;

    while (m --)
    {
        int u , v , w;
        cin >> u >> v >> w;

        edge.push_back({w , u , v});
    }
    
    sort(all(edge));

    int ans = 2e9 + 9;

    for (int i = 0 ; i < edge.size() ; i ++)
    {
        for (int i = 1 ; i<= n ; i ++)
            par[i] = i , sz[i] = 1;

        int mn = edge[i][0] , mx = -1e9;

        join(edge[i][1] , edge[i][2]);

        for (int j = i + 1 ; j < edge.size() ; j ++)
        {
            if (join(edge[j][1] , edge[j][2]))
                mx = max(edge[j][0] , mx);
        }

        bool ok = true;

        for (int i = 1 ; i<= n ; i ++)
            if (find(1) != find(i))
                ok = false;

        if (ok)
            ans = min(ans , mx - mn);
    }

    if (ans == 2e9 + 9)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
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