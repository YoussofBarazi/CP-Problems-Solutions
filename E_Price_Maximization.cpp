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

    vl a(n);
    set<pair<ll, ll>> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        s.insert({a[i] % k, i});
    }

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        ll need = a[i] % k;

        if (!s.count({need, i}))
            continue;

        s.erase({need, i});

        auto x = s.lower_bound({k - need, 0});

        if (x == s.end())
        {
            x = s.begin();
        }

        sum += (a[x->second] + a[i]) / k;

        s.erase(x);
    }

    cout << sum << endl;
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