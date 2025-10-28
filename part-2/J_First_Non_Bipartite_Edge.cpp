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

    int i = 1 , ndx = 0;

    vector <int> col(n + 1 , -1);

    while (m --)
    {
        int u , v;
        cin >> u >> v;

        if (!join(u , v) && col[u] == col[v])
            ndx = i;

        if (col[u] == -1 && col[v] == -1)
        {
            col[u] = 1;
            col[v] = 0;
        }
        else if (col[v] == -1)
        {
            col[v] = !col[u];
        }
        else if (col[u] == -1)
        {
            col[u] = !col[v];
        }

        i ++;
    }

    cout << ndx << endl;
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