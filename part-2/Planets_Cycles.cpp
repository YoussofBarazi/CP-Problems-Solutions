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

const int N = 200009;

int adj[N];
bool vis[N];
int ans[N];
queue <int> path;

void dfs(int u , int &len)
{
    path.push(u);
    
    if (vis[u])
    {
        len += ans[u];
        return ;
    }

    len ++;

    vis[u] = true;
    dfs(adj[u] , len);
}


void solve()
{
    int n;
    cin >> n;

    for (int i = 1 ; i <= n ; i ++)
        cin >> adj[i];

    for (int i = 1 ; i <= n ; i ++)
    {
        if (vis[i])
            continue;

        int teleports = 0;
        dfs(i , teleports);

        int dec = 1;

        // cout << i << endl;

        while (path.size())
        {
            if (path.front() == path.back())
                dec = 0;
            
            ans[path.front()] = teleports;
            // cout << path.front() << " " << teleports << endl;

            path.pop();
            teleports -= dec;
        }
    }

    for (int i = 1 ; i <= n ; i ++)
        cout << ans[i] << " " ;
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