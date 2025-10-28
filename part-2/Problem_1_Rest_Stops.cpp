#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
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
    ll l, n, f, b;
    cin >> l >> n >> f >> b;

    vector<int> x(l + 1, -1);
    vector<bool> passed(n, false);
    vector<pair<ll, int>> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i].S >> a[i].F;

    sort(allrev(a));

    for (int i = 0; i < n; i++)
        x[a[i].S] = i;

    ll ans = 0, time1 = 0, time2 = 0, p = 0;

    for (int i = 1; i <= l; i++)
    {
        while (p < n && passed[p])
            p++;

        time1 += f;
        time2 += b;

        if (x[i] == p && time1 > time2)
        {
            ans += (time1 - time2) * a[p].F, time2 = time1;
            passed[p] = true;
        }
        else if (x[i] != -1)
            passed[x[i]] = true;
    }

    cout << ans << endl;
}

int main()
{
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);

    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}