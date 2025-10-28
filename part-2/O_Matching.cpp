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

const int N = 21;

bool a[N][N];
int dp[1 << N];

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int mod = 1e9 + 7;

    dp[0] = 1;

    for (int s = 0; s < (1 << n); s++)
    {
        int i = __builtin_popcount(s);

        for (int j = 0; j < n; j++)
        {
            if (s & (1 << j) || !a[i][j])
                continue;
            
            dp[s ^ (1 << j)] = (dp[s] + dp[s ^ (1 << j)]) % mod;
        }
    }

    cout << dp[(1 << n) - 1] << endl;
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