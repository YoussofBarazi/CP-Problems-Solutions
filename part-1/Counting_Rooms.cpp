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

const int N = 1009;

int n , m;
char building[N][N];
bool vis[N][N];


void dfs (int x , int y)
{
    if (x < 0 || y < 0 || x == n || y == m || vis[x][y] || building[x][y] == '#')
        return;
    
    vis[x][y] = true;

    dfs(x , y + 1);
    dfs(x , y - 1);
    dfs(x + 1 , y);
    dfs(x - 1 , y);
}

void solve()
{
    cin >> n >> m;

    for (int i = 0 ; i < n ; i ++)
        for (int j = 0 ; j < m ; j ++)
            cin >> building[i][j];

    int cnt = 0;
    for (int i = 0 ; i < n ; i ++)
        for (int j = 0 ; j < m ; j ++)
            if (!vis[i][j] && building[i][j] == '.')
                cnt ++ , dfs(i , j);

    cout << cnt << endl;
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