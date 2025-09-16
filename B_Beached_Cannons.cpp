#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define oo INT_MAX
#define OO LONG_MAX
#define pb push_back
#define x first
#define y second
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
    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    pair<double, double> top;

    double a = (y2 * x1 - x2 * y1) / (x2 * x2 * x1 - x2 * x1 * x1);
    double b = (y1 - a * x1 * x1) / x1;

    double ans = (-1) * b / a;

    cout << fixed << setprecision(15);
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