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

const int N = 109, M = 2e5 + 7;
const ll INF = 1e16L + 7;

int n, W;
ll w[N], v[N];
ll mem[N][M];
bool vis[N][M];

ll dp(int i, int val)
{
    if (i == n)
    {
        if (val > 0)
            return INF;
        else 
            return 0;
    }

    ll &ret = mem[i][val];

    if (vis[i][val])
        return ret;

    vis[i][val] = true;

    ret = dp(i + 1, val);

    if (val - v[i] >= 0)
        ret = min(ret, dp(i + 1, val - v[i]) + w[i]);

    return ret;
}

void solve()
{
    cin >> n >> W;

    int max_value = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
        max_value += v[i];
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= max_value; j++)
            mem[i][j] = INF;

    for (int i = max_value; i >= 0; i--)
        if (dp(0, i) <= W)
        {
            cout << i << endl;
            return;
        }
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