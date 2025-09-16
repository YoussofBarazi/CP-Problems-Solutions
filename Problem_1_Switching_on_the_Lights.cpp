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

const int N = 109;

int n , m;
bool lited[N][N];
bool vis[N][N];
map <pii , vector <pii>> lits;

int dfs(int x , int y)
{
    if (x < 1 || y < 1 || x > n || y > n || vis[x][y] || !lited[x][y])
        return 0;

    vis[x][y] = true;

    int cnt = 0;

    cnt += dfs(x , y + 1) + dfs(x , y - 1) + dfs(x + 1 , y) + dfs(x - 1 , y);

    for (auto x : lits[{x , y}])
    {
        int i = x.F , j = x.S;

        cnt += !lited[i][j];
        lited[i][j] = true;

        if (!vis[i][j] && (vis[i][j + 1] || vis[i][j - 1] || vis[i - 1][j] || vis[i + 1][j]))
            cnt += dfs(i , j);
    }

    return cnt ;
}

void solve()
{
    cin >> n >> m;

    while (m --)
    {
        int x , y , a , b;
        cin >> x >> y >> a >> b;

        lits[{x , y}].pb({a , b});
    }

    lited[1][1] = true;
    vis[0][1] = true;

    int ans = 1 + dfs(1 , 1);

    cout << ans << endl;
}

int main()
{
    freopen("lightson.in" , "r" , stdin);
    freopen("lightson.out" , "w" , stdout);

    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}