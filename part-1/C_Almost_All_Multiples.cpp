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
    int n, x;
    cin >> n >> x;

    if (n % x)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> ans(n + 1);

    for (int x = 1; x <= n; x++)
        ans[x] = x;

    ans[1] = x, ans[n] = 1;

    while (x < n)
        for (int i = x * 2; i <= n; i += x)
            if (n % i == 0)
            {
                ans[x] = i;
                x = i;
                break;
            }

    for (int x = 1; x <= n; x++)
        cout << ans[x] << " ";

    cout << endl;
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