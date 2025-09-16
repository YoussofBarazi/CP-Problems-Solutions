#include <bits/stdc++.h>

#define F first
#define S second
#define ll long long
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
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
vector <int> stk;
vector <bool> vis(N);

void DFS(int u) {
    vis[u] = true;

    for (auto v : adj[u]) {
        if (vis[v]) continue;
        DFS(v);
    }
    stk.push_back(u);
}

void solve()
{
    int n , m;
    cin >> n >> m;
    
    for (int i = 0 ; i < m ; i ++) {
        int a , b;
        cin >> a >> b;

        adj[a].push_back(b);
    }

    for (int i = 1 ; i <= n ; i ++) DFS(i);

    vector <int> dp(n + 1 , -N) , to(n + 1 , -1);
    dp[n] = 1;

    for (int i = 0 ; i < n ; i ++) {
        int u = stk[i];
        for (auto v : adj[u]) {
            if (dp[u] < dp[v] + 1) {
                dp[u] = dp[v] + 1; 
                to[u] = v;
            }
        }
    }

    if (dp[1] <= 0) {
        cout << "IMPOSSIBLE\n";
        return ;
    }

    cout << dp[1] << endl;

    int x = 1;
    while (x != -1) {
        cout << x << " ";
        x = to[x];
    }
}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}