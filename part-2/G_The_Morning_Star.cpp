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
    scanf("%d", &n);

    map<ll, ll> a, b, c, d;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        a[x]++;
        b[y]++;
        c[y - x]++;
        d[x + y]++;
    }

    ll ans = 0;
    for (auto x : a)
        ans += x.S * (x.S - 1);
    for (auto x : b)
        ans += x.S * (x.S - 1);
    for (auto x : c)
        ans += x.S * (x.S - 1);
    for (auto x : d)
        ans += x.S * (x.S - 1);

    printf("%lld\n", ans);
}

int main()
{
    IOS;

    int t = 1;
    scanf("%d", &t);

    while (t--)
    {
        solve();
    }

    return 0;
}