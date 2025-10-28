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

const int N = 501, M = 125251 , mod = 1e9 + 7;

ll ways[N][M];

void solve()
{
    int n, set_sum, total;
    cin >> n;

    total = n * (n + 1) / 2;
    set_sum = total / 2;

    if (set_sum * 2 != total)
    {
        cout << 0 << endl;
        return ;
    }

    ways[0][0] = 1;

    for (int i = 1 ; i < n ; i ++)
    {
        for (int j = 0 ; j <= set_sum ; j ++)
        {
            ways[i][j] = ways[i - 1][j];

            if (j - i >= 0)
                (ways[i][j] += ways[i - 1][j - i]) %= mod;
        }
    }

    cout << ways[n - 1][set_sum];
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

void IO(string name = "")
{

    cin.tie(0)->sync_with_stdio(0);
    if (name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}