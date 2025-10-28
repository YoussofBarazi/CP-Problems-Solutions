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
int k, n;

bool ok(ll m, vector<ll> &a)
{
    ll sum = 0;

    for (auto x : a)
        sum += min(m, x);

    return sum >= m * k;
}

void solve()
{
    cin >> k >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll l = 1, r = 1;
    while (ok(r, a))
        r *= 2;

    while (l < r)
    {
        ll mid = (l + r + 1) / 2;

        if (ok(mid, a))
            l = mid;
        else
            r = mid - 1;
    }

    cout << l << endl;
}

int main()
{
    IOS;

    int t = 1;
    //   cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}