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
#define Sort(a) sort(a.begin(), a.end())
#define Rsort(a) sort(a.rbegin(), a.rend())
#define UB(a, t) upper_bound(a.begin(), a.end(), t) - a.begin()
#define LB(a, t) lower_bound(a.begin(), a.end(), t) - a.begin()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

void solve()
{
    int n , m , i1 , j1 , i2 , j2;
    string d;
    cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> d;
    i1 -- , i2 -- , j1 -- , j2 --;
    vi a[n];
    for (size_t i = 0; i < n; i++)
    {
        a[i].resize(m , 0);
    }
    int x = i1 , y = j1 , cnt = 0;
    while (a[x][y] < 10)
    {
        if (d == "DL")
        {
            while (x < n && y >= 0)
            {
                a[x][y] ++;
                if (x == i2 && y == j2)
                {
                    cout << cnt << endl;
                    return;
                }
                x ++ , y --;
            }
        }
        else if (d == "DR")
        {
            while (x < n && y < m)
            {
                a[x][y] ++;                
                if (x == i2 && y == j2)
                {
                    cout << cnt << endl;
                    return;
                }
                x ++ , y ++;
            }
        }
        else if (d == "UR")
        {
            while (x >= 0 && y < m)
            {
                a[x][y] ++;
                if (x == i2 && y == j2)
                {
                    cout << cnt << endl;
                    return;
                }
                x -- , y ++;
            }
        }
        else if (d == "UL")
        {
            while (x >= 0 && y >= 0)
            {
                a[x][y] ++;
                if (x == i2 && y == j2)
                {
                    cout << cnt << endl;
                    return;
                }
                x -- , y --;
            }
        }
        cnt ++;
        if (x == n && y == m) d = "UL" , x = n - 2 , y = m - 2;
        else if (x == n && y == -1) d = "UR" , x = n - 2 , y = 1;
        else if (x == -1 && y == m) d = "DL" , x = 1 , y = m - 2;
        else if (x == -1 && y == -1) d = "DR" , x = 1 , y = 1;
        else if (x == n) d[0] = (d[0] == 'U')? 'D' : 'U' , x = n - 2;
        else if (y == m) d[1] = (d[1] == 'R')? 'L' : 'R' , y = m - 2;
        else if (x == -1) d[0] = (d[0] == 'U')? 'D' : 'U' , x = 1;
        else d[1] = (d[1] == 'R')? 'L' : 'R' , y = 1;
    }
    cout << -1 << endl;
}

int main()
{
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}