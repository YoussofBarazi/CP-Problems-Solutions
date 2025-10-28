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

    vi a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> v(n, 0);
    for (size_t i = 1; i < n; i++)
    {
        if (a[i] * 2 > a[i - 1])
            v[i] = 1;
    }

    int cnt = 0;
    for (size_t i = 1; i <= k; i++)
    {
        cnt += v[i];
    }

    int ans = cnt == k;
    for (size_t i = k + 1; i < n; i++)
    {
        cnt += v[i];
        cnt -= v[i - k];
        ans += cnt == k;
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