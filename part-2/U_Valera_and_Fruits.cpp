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

void solve()
{
    int n, v;
    cin >> n >> v;

    vector<int> a(3009, 0);

    int day = 1;
    for (size_t i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x] += y;
    }
    
    int ans = 0;

    while (day <= 3002)
    {
        if (a[day] + a[day - 1] <= v)
        {
            ans += a[day] + a[day - 1];
            a[day] -= min(a[day] , v);
        }
        else 
        {
            ans += v;
            a[day] -= max(v - a[day - 1] , 0);
        }
        day ++;
    }

    cout << ans << endl;
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