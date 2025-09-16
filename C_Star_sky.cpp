#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define oo INT_MAX
#define OO LONG_MAX
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend() 
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

int ps[11][102][102];

void solve()
{
    int n , q , c;
    cin >> n >> q >> c;

    for (size_t i = 0; i < n; i++)
    {
        int x , y , s;
        cin >> x >> y >> s;

        for (size_t i = 0; i < c + 1; i++)
        {
            ps[i][x][y] += s;
            s++;
            s %= c + 1;
        }
    }
    
    for (size_t i = 0; i < c + 1; i++)
    {
        for (size_t j = 1; j < 101; j++)
        {
            for (size_t k = 1; k < 101; k++)
            {
                ps[i][j][k] += ps[i][j - 1][k] + ps[i][j][k - 1] - ps[i][j - 1][k - 1];
            }
        }
    }
    
    for (size_t i = 0; i < q; i++)
    {
        int x1 , x2 , y1 , y2 , t;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        t %= c + 1;

        int ans = ps[t][x2][y2] - ps[t][x1 - 1][y2] - ps[t][x2][y1 - 1] + ps[t][x1 - 1][y1 - 1];

        cout << ans << endl;
    }
}

int main()
{
    IOS;

    int t = 1;
    //cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}