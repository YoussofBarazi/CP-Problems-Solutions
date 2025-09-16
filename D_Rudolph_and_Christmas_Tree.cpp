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
    double d, h;
    cin >> n >> d >> h;

    vector<double> a(n);
    double res = 0;
    double tan = 2 * h / d;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        res += h * d / 2.0;
    }

    for (int i = 1; i < n; i++)
    {
        double height = h - a[i] + a[i - 1];
        double base = 2 * height / tan;

        height = max(height, 0.0);

        res -= (height * base / 2.0);
    }

    cout << fixed << setprecision(10);
    cout << res << endl;
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