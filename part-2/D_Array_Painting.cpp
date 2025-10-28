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

    vi a;
    int cost = 0, mx = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x == 0)
        {
            if (mx != 0)
                a.pb(mx);

            a.pb(0);

            mx = 0;
        }

        mx = max(mx, x);
    }

    if (mx != 0)
        a.pb(mx);

    n = a.size();
    vector<bool> painted(n, false);

    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] == 2)
        {
            if (!painted[i])
                painted[i] = true, cost++;

            painted[i + 1] = true;
            painted[i - 1] = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            if (!painted[i])
                painted[i] = true, cost++;

            if (i > 0 && !painted[i - 1])
                painted[i - 1] = true;
            else if (i + 1 < n)
                painted[i + 1] = true;
        }
    }

    for (auto x : painted)
        cost += !x;

    cout << cost << endl;
}

int main()
{
    IOS;

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}