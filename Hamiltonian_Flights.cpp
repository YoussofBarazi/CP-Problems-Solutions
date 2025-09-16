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

const int N = 200009;

int n, m;
vector<int> adj[21];
int dp[1 << 20][21];

void solve()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[v - 1].push_back(u - 1);
    }

    int mod = 1e9 + 7;

    dp[1][0] = 1;

    for (int s = 2; s < (1 << n); s++)
    {
        if ((s & (1 << (n - 1))) && s != ((1 << n) - 1))
            continue;
            
        for (int i = 0; i < n; i++)
        {
            if (s & (1 << i))
                for (int x : adj[i])
                {
                    if (s & (1 << x))
                    {
                        dp[s][i] = (dp[s][i] + dp[s ^ (1 << i)][x]) % mod;
                    }
                }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << endl;
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