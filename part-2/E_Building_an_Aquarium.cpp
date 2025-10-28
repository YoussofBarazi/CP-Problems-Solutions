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

int n, x;
vector<int> a;

bool ok(ll h)
{
    ll units = 0;

    for (int i = 0; i < n; i++)
    {
        units += max(h - a[i], 0ll);

        if (units > x)
            return false;
    }

    return true;
}

void solve()
{
    cin >> n >> x;

    a.resize(n);
    for (int &x : a)
        cin >> x;

    ll l = 1, r = 2e12;
    while (l + 1 < r)
    {
        ll m = (l + r) / 2;

        if (ok(m))
            l = m;
        else
            r = m;
    }

    cout << l << endl;
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