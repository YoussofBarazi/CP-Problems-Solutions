#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
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

ll bascal_triangle(int n, int k)
{
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));

    for (int i = 0; i <= n; i++)
    {

        dp[i][0] = 1;

        if (i <= k)
        {
            dp[i][i] = 1;
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= min(i, k); j++)
        {
            if (i != j)
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[n][k];
}

void solve()
{
    ll n, m, t;
    cin >> n >> m >> t;

    ll ans = 0;
    for (int i = 4; i < t; i++)
    {
        ans += bascal_triangle(n, i) * bascal_triangle(m, t - i);
    }

    cout << ans << endl;
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