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

    vl a(n);

    ll mx = 0;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx , a[i]);
    }
    
    ll x = a[0];
    bool ok = true;

    for (size_t i = 1; i < n; i++)
    {
        if (abs(a[i] - x) < abs(a[i - 1] - x))
        {
            ok = false;
            break;
        }
    }
    if (ok) 
    {
        cout << x << endl;
        return;
    }
    x -= 1;
    ok = true;
    for (size_t i = 1; i < n; i++)
    {
        if (abs(a[i] - x) < abs(a[i - 1] - x))
        {
            ok = false;
            break;
        }
    }
    if (ok)
    {
        cout << x << endl;
        return;
    }
    ok = true;
    x = mx - a[n - 1] - 1;
        for (size_t i = 1; i < n; i++)
    {
        if (abs(a[i] - x) < abs(a[i - 1] - x))
        {
            ok = false;
            break;
        }
    }
    if (ok)
    {
        cout << x << endl;
        return;
    }
    x = 40714056;
    ok = true;
        for (size_t i = 1; i < n; i++)
    {
        if (abs(a[i] - x) < abs(a[i - 1] - x))
        {
            ok = false;
            break;
        }
    }
    if (ok)
    {
        cout << x << endl;
        return;
    }
    cout << -1 << endl;
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