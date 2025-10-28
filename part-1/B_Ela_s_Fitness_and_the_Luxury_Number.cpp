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
    ll l , r;
    cin >> l >> r;

    ll x = sqrt(l);
    ll ans1 = x * 3;

    if (x * x == l) ans1 --;
    if (x * x + x >= l) ans1 --; 
    if (x * x + x * 2 >= l) ans1 --;

    ll y = sqrt(r);
    ll ans2 = y * 3;

    if (y * y + y > r) ans2 --;
    if (y * y + 2 * y > r) ans2 --;

    ll ans = ans2 - ans1;

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