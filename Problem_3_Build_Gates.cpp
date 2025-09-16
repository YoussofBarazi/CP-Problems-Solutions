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

const int N = 4009;

bool vis[N][N];
int MINX = 1e9 , MAXX = 0 , MINY = 1e9 , MAXY = 0;

void dfs(int i , int j)
{
    if (i < MINX || i > MAXX || j < MINY || j > MAXY || vis[i][j]) {
		return;
	}

    vis[i][j] = true;

    dfs(i , j + 1);
    dfs(i , j - 1);
    dfs(i + 1 , j);
    dfs(i - 1 , j);
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int x = 2002 , y = 2002;
    vis[x][y] = true;
    
    for (int i = 0 ; i < n ; i ++)
    {
        y += int(s[i] == 'N') - int(s[i] == 'S');
        x += int(s[i] == 'E') - int(s[i] == 'W');
        vis[x][y] = true;
        y += int(s[i] == 'N') - int(s[i] == 'S');
        x += int(s[i] == 'E') - int(s[i] == 'W');
        vis[x][y] = true;

        MINX = min(x , MINX);
        MAXX = max(MAXX , x);
        MINY = min(MINY , y);
        MAXY = max(MAXY , y);

    }

    MINX -- , MINY -- , MAXX ++ , MAXY ++;

    int cnt = 0;

    for (int i = MINX ; i <= MAXX ; i ++)
    {
        for (int j = MINY ; j <= MAXY ; j ++)
        {
            if (!vis[i][j])
            {
                cnt ++ ;
                dfs(i , j);
            }
        }
    }

    cout << cnt - 1 << endl;
}

int main()
{   
    freopen("gates.in" , "r" , stdin);
    freopen("gates.out" , "w" , stdout);

    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}