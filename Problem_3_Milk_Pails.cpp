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

const int N = 209;

bool vis[N][N][N];
int ans = 1e9;
int X , Y , k , m;

void dfs(int x , int y , int cnt)
{
    if (x >= N || y >= N || cnt > k || vis[x][y][cnt])
        return;

    vis[x][y][cnt] = true;

    ans = min({abs(m - x - y) , ans});

    dfs(X , y , cnt + 1);
    dfs(x , Y , cnt + 1);
    
    dfs(0 , y , cnt + 1);
    dfs(x , 0 , cnt + 1);
    
    int w = min(X - x , y);
    dfs(x + w , y - w , cnt + 1);    
    
    w = min(x , Y - y);
    dfs(x - w , y + w , cnt + 1);
}

void solve()
{
    cin >> X >> Y >> k >> m;

    dfs(0 , 0 , 0);

    cout << ans << endl;
}

int main()
{
    freopen("pails.in" , "r" , stdin);
    freopen("pails.out" , "w" , stdout);

    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}