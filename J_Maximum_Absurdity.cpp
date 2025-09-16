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
    ll n, k;
    cin >> n >> k;

    vl sum(n + 1, 0);
    for (size_t i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }

    ll a = 0, mx1 = 0 , mx2 = 0, b = 0;
    pl ans;
    for (size_t i = 1; i + k - 1 <= n; i++)
    {
        if (mx1 < sum[i + k - 1] - sum[i - 1])
        {
            mx1 = sum[i + k - 1] - sum[i - 1];
            a = i;
            for (size_t i = a + k; i + k - 1 <= n; i++)
            {
                if (mx2 < sum[i + k - 1] - sum[i - 1] + mx1)
                {
                    mx2 = sum[i + k - 1] - sum[i - 1] + mx1;
                    ans = {a , i};
                }
            }
        }
    }

    cout << ans.F << " " << ans.S << endl;
}

int main()
{
    IOS;

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}