#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
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
    ll x[7], y[7];

    for (int i = 1; i < 7; i++)
        cin >> x[i] >> y[i];

    ll intersection_area = 0;

    ll a1 = max(x[1], x[3]), b1 = max(y[1], y[3]);
    ll a2 = min(x[2], x[4]), b2 = min(y[2], y[4]);

    if (a1 <= a2 && b1 <= b2)
    {
        intersection_area += (a2 - a1) * (b2 - b1);
    }

    ll a3 = max(x[1], x[5]), b3 = max(y[1], y[5]);
    ll a4 = min(x[2], x[6]), b4 = min(y[2], y[6]);

    if (a3 <= a4 && b3 <= b4)
    {
        intersection_area += (a4 - a3) * (b4 - b3);
    }

    ll a5 = max(a1, a3), b5 = max(b1, b3);
    ll a6 = min(a2, a4), b6 = min(b2, b4);

    if (a5 <= a6 && b5 <= b6)
    {
        intersection_area -= (a6 - a5) * (b6 - b5);
    }

    ll white_area = (x[2] - x[1]) * (y[2] - y[1]);

    if (intersection_area == white_area)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}