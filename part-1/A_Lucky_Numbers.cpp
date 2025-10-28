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
    int l , r;
    cin >> l >> r;

    int ans = 0 , mx = 0;
    for (size_t i = l; i <= min(r * 1.0, l + 1e3); i++)
    {
        int x = i , mn1 = 10 , mx1 = 0;
        while (x > 0)
        {
            mn1 = min(mn1 , x % 10);
            mx1 = max(mx1 , x % 10);
            x /= 10;
        }

        if (mx1 - mn1 >= mx)
        {
            ans = i;
            mx = mx1 - mn1;
        }
    }
    
    cout << ans << endl;
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