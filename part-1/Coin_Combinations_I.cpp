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

const int N = 1000009;

int n, x, mod = 1e9 + 7, c[100];
ll dp[N];
bool vis[N];

int f(int sum)
{
    if (sum == x)
        return 1;

    if (vis[sum])
        return dp[sum];

    vis[sum] = true;

    for (int i = 0; i < n; i++)
    {
        if (sum + c[i] <= x)
        {
            dp[sum] += f(sum + c[i]);
        
            if (dp[sum] >= mod)
                dp[sum] -= mod;
        }
    }

    return dp[sum];
}

void solve()
{
    cin >> n >> x;

    for (int i = 0; i < n; i++)
        cin >> c[i];

    cout << f(0) << endl;
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