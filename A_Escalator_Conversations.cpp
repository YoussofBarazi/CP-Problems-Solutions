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
    ll n, m, k, H;
    cin >> n >> m >> k >> H;

    vl h(n);
    for (auto &x : h)
        cin >> x;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll x = abs(h[i] - H);
        if (x % k == 0 && x / k < m && x > 0)
            ans++;
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