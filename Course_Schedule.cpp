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
vector <int> ans;

bool DFS(int u)
{
    color[u] = 1;

    bool DAG = true;

    for (auto v : adj[u])
    {

        if (color[v] == 2)
            continue;
        if (color[v] == 1)
            return false;

        DAG &= DFS(v);
    }

    color[u] = 2;
    ans.push_back(u);

    return true;
}

void solve()
{
    int n , m;
    cin >> n >> m;

    vector <int> indeg(n + 1 , 0);

    while (m --)
    {
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        indeg[v] ++;
    }

    bool DAG = true;

    for (int i = 1 ; i <= n ; i ++)
        if (indeg[i] == 0)
            DAG &= DFS(i);

    if (!DAG || ans.size() != n)
    {
        cout << "IMPOSSIBLE\n";
        return ; 
    }

    reverse(all(ans));

    for (auto x : ans)
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