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

const int N = 300009;

ll DP[20][N][20];

void solve()
{
    int n , q;
    cin >> n >> q;

    vector <string> grid;

    for (int i = 0 ; i < n ; i ++)
    {
        DP[i][0][i] = 1;
    }

    int i = -1;

    while (q --)
    {
        string t , s;
        cin >> t;

        if (t[0] == 'a')
        {
            cin >> s;

            grid.push_back(s);
            
            i ++;
            if (grid.size() == 1)
                continue;

            for (int j = 0 ; j < n ; j ++)
            {
                for (int t = 0 ; t < n ; t ++)
                    if (j > 0 && grid[i - 1][j - 1] == grid[i][j] && grid[i][j] == grid[0][t])
                        DP[t][i][j] += DP[t][i - 1][j - 1];

                for (int t = 0 ; t < n ; t ++)
                    if (j + 1 < n && grid[i - 1][j + 1] == grid[i][j] && grid[i][j] == grid[0][t])
                        DP[t][i][j] += DP[t][i - 1][j + 1];

                for (int t = 0 ; t < n ; t ++)
                    if (grid[i - 1][j] == grid[i][j] && grid[i][j] == grid[0][t])
                        DP[t][i][j] += DP[t][i - 1][j];
            }
        }
        else if (t[0] == 'p')
        {
            int c , d;
            cin >> c >> d;

            cout << DP[d - 1][i][c - 1] << endl;
        }
        else 
        {
            for (int j = 0 ; j < n ; j ++)
            {
                for (int t = 0 ; t < n ; t ++)
                        DP[t][i][j] = 0;
            }

            i --;
            grid.pop_back();
        }
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