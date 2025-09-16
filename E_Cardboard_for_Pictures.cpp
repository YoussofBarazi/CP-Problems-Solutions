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
ll n, c;
vector<int> s;

ll calc(ll m)
{
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (s[i] + 2 * m) * (s[i] + 2 * m);

        if (sum > c)
            return sum;
    }

    return sum;
}

void solve()
{
    cin >> n >> c;
    s.resize(n);
    for (auto &x : s)
        cin >> x;

    ll l = 0, r = 1e9;

    while (l <= r)
    {
        ll m = (l + r) / 2;

        ll s = calc(m);

        if (s == c)
        {
            cout << m << endl;
            return;
        }
        else if (s > c)
            r = m - 1;
        else
            l = m + 1;
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