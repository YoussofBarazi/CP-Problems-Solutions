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

void solve()
{
    int n, k;
    cin >> n >> k;

    vi sum[n + 1];
    for (size_t i = 1; i <= n; i++)
    {
        sum[i].resize(n + 1, 0);
        for (size_t j = 1; j <= n; j++)
        {
            cin >> sum[i][j];
            sum[i][j] += sum[i][j - 1];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int t = k, row = i, s = 0;
            while (t >= 0 && row > 0)
            {
                s += sum[row][min(j + t, n)] - sum[row][max(j - t - 1, 0)];
                t--, row--;
            }
            row = i + 1, t = k - 1;
            while (t >= 0 && row <= n)
            {
                s += sum[row][min(j + t, n)] - sum[row][max(j - t - 1, 0)];
                t--, row++;
            }
            ans = max(ans, s);
        }
    }

    cout << ans << endl;
}

int main()
{
    IOS;

    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}