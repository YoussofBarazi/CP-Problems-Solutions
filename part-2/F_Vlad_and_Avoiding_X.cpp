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

const int N = 8;

int DP[N][1 << N][1 << N];
char s[20][20];

int dp(int row , int prev1 , int prev2)
{
    if (row == 7)
        return 0;

    int &ret = DP[row][prev1][prev2];

    if (ret != -1)
        return ret;

    ret = 49;

    int cur = 0;

    for (int col = 0 ; col < 7 ; col ++)
        if (s[row][col] == 'B') cur |= (1 << col); 

    for (int mask = 0 ; mask < 128 ; mask ++)
    {
        int cnt = 0 , ok = true;

        for (int col = 0 ; col < 7 ; col ++)
        {
            if ((cur & (1 << col)) && !(mask & (1 << col)))
                cnt ++;
            
            if (!(cur & (1 << col)) && (mask & (1 << col)))
            {
                ok = false;
                break;
            }
            else if 
            (
                mask & (1 << col) && mask & (1 << (col + 2)) &&
                prev1 & (1 << (col + 1)) &&
                prev2 & (1 << col) && prev2 & (1 << (col + 2))
            ) 
            {
                ok = false;
                break;
            }
        }

        if (ok)
            ret = min(ret , dp(row + 1 , mask , prev1) + cnt);
    }

    return ret;
}

void solve()
{
    for (int i = 0 ; i < 7 ; i ++)
        for (int j = 0 ; j < 7 ; j ++)
            cin >> s[i][j];

    memset(DP , -1 , sizeof DP);

    cout << dp(0 , 0 , 0) << endl;
}

int main()
{
    IOS;

    for (int i = 0 ; i < 20 ; i ++)
        for (int j = 0 ; j < 20 ; j ++)
            s[i][j] = 'W';

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}