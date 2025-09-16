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
#define Sort(a) sort(a.begin(), a.end())
#define Rsort(a) sort(a.rbegin(), a.rend())
#define UB(a, t) upper_bound(a.begin(), a.end(), t) - a.begin()
#define LB(a, t) lower_bound(a.begin(), a.end(), t) - a.begin()
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

    vector<pair<int, int>> a(n), ans;
    int cnt1 = 0, cnte = 1;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i].F;
        if (i > 0 && a[i - 1].F == a[i].F)
            cnte++;
        if (a[i].F == 1)
            cnt1++;
        a[i].S = i + 1;
    }

    if (cnte == n)
    {
        cout << 0 << endl;
        return;
    }
    if (cnt1 > 0)
    {
        cout << -1 << endl;
        return;
    }

    Rsort(a);
    for (size_t i = 1; i < n; i++)
    {
        while (a[i - 1].F > a[i].F && a[i - 1].F > 3)
        {
            a[i - 1].F = (a[i - 1].F + a[i].F - 1) / a[i].F;
            ans.pb({a[i - 1].S, a[i].S});
        }
    }

    while (a[n - 1].F > a[n - 2].F && a[n - 1].F > 3)
    {
        a[n - 1].F = (a[n - 1].F + a[n - 2].F - 1) / a[n - 2].F;
        ans.pb({a[n - 1].S, a[n - 2].S});
    }


    for (size_t i = 0; i < 100; i++)
    { 
        Sort(a);
        for (size_t i = 1; i < n; i++)
        {
            while (a[i].F > a[i - 1].F && a[i].F > 2)
            {
                a[i].F = (a[i].F + a[i - 1].F - 1) / a[i - 1].F;
                ans.pb({a[i].S, a[i - 1].S});
            }
        }
    }

    cnte = 1;
    for (size_t i = 1; i < n; i++)
    {
        if (a[i].F == a[i - 1].F)
            cnte++;
    }

    if (cnte == n)
    {
        cout << ans.size() << endl;
        for (auto x : ans)
        {
            cout << x.F << " " << x.S << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }
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