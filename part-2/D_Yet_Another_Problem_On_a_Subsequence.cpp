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

int n, mod = 998244353;
int a[N];
ll mem[N][N];
bool vis[N][N];

ll dp(int i, int j)
{
    if (i == n)
    {
        return j == 0;
    }

    ll &ret = mem[i][j];

    if (vis[i][j])
        return ret;

    vis[i][j] = true;

    if (j == 0)
    {
        ret = dp(i + 1, 0);

        if (0 < a[i] && a[i] < n)
            ret += dp(i + 1, a[i]);
    }
    else
        ret = dp(i + 1, j - 1) + dp(i + 1, j);

    return ret %= mod;
}

void solve()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << (dp(0, 0) + mod - 1) % mod << endl;
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