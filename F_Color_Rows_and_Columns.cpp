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

const int N = 1009;

int width[N] , height[N];
int costs[500][101][101];

void precalc()
{
    for (int i = 1 ; i <= 100 ; i ++)
    {
        for (int j = 1 ; j <= 100 ; j ++)
        {
            int w = i , h = j , cost = 0 , ans = 0;

            while (w >= 1 && h >= 1)
            {
                if (w < h)
                {
                    cost += w;
                    h --; 
                }
                else 
                {
                    cost += h;
                    w --;
                }
                ans ++;
                costs[ans][i][j] = cost;
            }
            ans ++;
            costs[ans][i][j] = cost;
        }
    }
}

int DP[N][101];
int n , k;

int dp(int i , int k)
{
    if (k == 0)
        return 0;

    if (i == n)
        return 1e5;
    
    int &ret = DP[i][k];
    
    if (ret != -1)
        return ret;
    
    ret = dp(i + 1 , k);

    for (int t = 1 ; t <= k ; t ++)
    {
        if (costs[t][width[i]][height[i]] <= 0)
            break;

        ret = min(ret , dp(i + 1 , k - t) + costs[t][width[i]][height[i]]);
    }

    return ret;
}

void solve()
{
    cin >> n >> k;

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> width[i] >> height[i];
    }

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = 0 ; j <= k ; j ++)
        {
            DP[i][j] = -1;
        }
    }

    int ans = dp(0 , k);

    if (ans >= 1e5)
        ans = -1;

    cout << ans << endl;
}

int main()
{
    IOS;
    precalc();
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}