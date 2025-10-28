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
    ll l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;

    if (a == b)
        cout << 0 << endl;
    else if (abs(a - b) >= x)
        cout << 1 << endl;
    else if ((abs(r - b) >= x && abs(a - r) >= x) || (abs(l - b) >= x && abs(a - l) >= x))
        cout << 2 << endl;
    else if ((abs(r - l) >= x && abs(a - r) >= x && abs(l - b) >= x) || (abs(l - r) >= x && abs(a - l) >= x && abs (r - b) >= x))
        cout << 3 << endl;
    else
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