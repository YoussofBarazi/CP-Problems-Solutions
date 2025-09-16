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
    return par[u] = (par[u] == u)? u : find(par[u]);
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

    for (int i = 1 ; i <= n ; i ++)
        par[i] = i , sz[i] = 1;

    vector <array<int , 3>> edge;

    while (m --)
    {
        int u , v , w;
        cin >> u >> v >> w;

        edge.push_back({w , u , v});
    }

    sort(all(edge));

    int ans = 0;

    for (auto e : edge)
    {
        if (join(e[1] , e[2]))
        {
            ans = max(ans , e[0]);
        }   
    }

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