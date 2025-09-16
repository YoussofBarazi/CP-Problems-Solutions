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

    vector<pi> a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i].F;
        a[i].S = i;
    }
    sort(all(a));

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(a[i].S - i) % k)
            cnt++;
    }

    int ans = 0;
    if (cnt == 2)
        ans = 1;
    if (cnt > 2)
        ans = -1;

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