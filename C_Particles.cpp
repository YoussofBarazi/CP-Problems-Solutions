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
    int n;
    cin >> n;

    vl a(n);
    ll mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        mx = max(mx, a[i]);
    }

    if (mx <= 0)
    {
        cout << mx << endl;
        return;
    }

    ll ans = mx;
    ll sum = 0;

    for (int i = 0; i < n; i += 2)
    {
        if (a[i] > 0)
            sum += a[i];
        ans = max(ans, sum);
    }

    sum = 0;
    for (int i = 1; i < n; i += 2)
    {
        if (a[i] > 0)
            sum += a[i];
        ans = max(sum, ans);
    }

    cout << ans << endl;
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