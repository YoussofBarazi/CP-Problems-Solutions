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

int par[N] , sz[N] , nxt[N];

int find(int u)
{
    return par[u] = (u == par[u])? u : find(par[u]);
}

void join(int u , int v)
{
    u = find(u);
    v = find(v);

    if (u == v)
        return ;
    
    if (sz[u] < sz[v])
        swap(u , v);

    sz[u] += sz[v];
    par[v] = u;
}

void solve()
{
    int n , q;
    cin >> n >> q;

    for (int i = 1 ; i <= n ; i ++)
        par[i] = i , sz[i] = 1 , nxt[i] = i + 1;

    while (q --)
    {
        int t , x , y;
        cin >> t >> x >> y;

        if (t == 1)
        {
            join(x , y);
        }
        else if (t == 2)
        {
            for (int i = x + 1 ; i <= y ;)
            {
                join(i , i - 1);
                
                int t = i;
                i = nxt[i];
                nxt[t] = nxt[y];
            }
        }
        else 
        {
            if (find(x) == find(y))
                cout << "YES" << endl;
            else 
                cout << "NO" << endl;
        }
    }
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