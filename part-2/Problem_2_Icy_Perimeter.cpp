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

int n;
char x[N][N];
bool vis[N][N];

void dfs(int i , int j , int &a , int &b)
{
    if (i < 1 || j < 1 || i > n || j > n || vis[i][j] || x[i][j] == '.')
        return;

    vis[i][j] = true;

    int cnt = (x[i][j + 1] == '.') + (x[i][j - 1] == '.') + (x[i + 1][j] == '.') + (x[i - 1][j] == '.');

    a ++ , b += cnt;

    dfs(i , j + 1 , a , b);
    dfs(i , j - 1 , a , b);
    dfs(i + 1 , j , a , b);
    dfs(i - 1 , j , a , b); 
}

void solve()
{
    cin >> n ;

    for (int i = 0 ; i <= n + 1 ; i ++)
        for (int j = 0 ; j <= n + 1 ; j ++)
            x[i][j] = '.';

    for (int i = 1 ; i <= n ; i ++)
        for (int j = 1 ; j <= n ; j ++)
            cin >> x[i][j];

    int area = 0 , perimeter = 1e9;
    for (int i = 1 ; i <= n ; i ++)
    {
        for (int j = 1 ; j <= n ; j ++)
        {
            int a = 0 , p = 0;
            if (!vis[i][j])
                dfs(i , j , a , p);

            if (area <= a)
            {
                if (area == a)
                    perimeter = min(perimeter , p);
                else 
                    perimeter = p;
                
                area = a; 
            }
        }
    }
    cout << area << " " << perimeter << endl;
}

int main()
{
    freopen("perimeter.in" , "r" , stdin);
    freopen("perimeter.out" , "w" , stdout);

    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}