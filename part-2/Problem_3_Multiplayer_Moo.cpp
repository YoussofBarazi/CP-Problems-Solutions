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

const int N = 250;

int n , a[N][N];
bool vis[N][N];
int ans1 = 0 , ans2 = 0;

void dfs1(int i , int j , int id , int cnt)
{  
    if (i < 0 || j < 0 || i >= n || j >= n || vis[i][j] || a[i][j] != id)
        return ;
  
    ans1 = max(cnt , ans1);

    vis[i][j] = true;

    dfs1(i , j + 1 , id , cnt + 1),
    dfs1(i , j - 1 , id , cnt + 1),
    dfs1(i + 1 , j , id , cnt + 1),
    dfs1(i - 1 , j , id , cnt + 1);
        
    return ;
}

void dfs2(int i , int j , int id1 , int id2 , int cnt)
{
    if (i < 0 || j < 0 || i >= n || j >= n || vis[i][j] || (a[i][j] != id1 && a[i][j] != id2 && id2 != -1))
        return ;

    vis[i][j] = true;
    ans2 = max(cnt , ans2);

    if (id1 != a[i][j])
        id2 = a[i][j];
    
    dfs2(i , j + 1 , id1 , id2 , cnt + 1),
    dfs2(i , j - 1 , id1 , id2 , cnt + 1),
    dfs2(i + 1 , j , id1 , id2 , cnt + 1),
    dfs2(i - 1 , j , id1 , id2 , cnt + 1);

    return ;
}

void solve()
{
    cin >> n;

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = 0 ; j < n ; j ++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = 0 ; j < n ; j ++)
        {
            if(!vis[i][j])
                dfs1(i , j , a[i][j] , 1);
        }
    }

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = 0 ; j < n ; j ++)
        {
            vis[i][j] = false;
        }
    }

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = 0 ; j < n ; j ++)
        {
            if(!vis[i][j])
                dfs2(i , j , a[i][j] , -1 , 1);
        }
    }

    cout << ans1 << endl;
    cout << ans2 << endl;
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