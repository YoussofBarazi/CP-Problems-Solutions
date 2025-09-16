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
    int W, H, x1, x2, y1, y2, w, h;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;

    int ans = 1e9;

    if (x2 - x1 + w <= W)
    {
        ans = min(ans, max(0, w - x1));
        ans = min(ans, max(0, x2 - (W - w)));
    }

    if (y2 - y1 + h <= H)
    {
        ans = min(ans, max(0, h - y1));
        ans = min(ans, max(0, y2 - (H - h)));
    }

    cout << fixed << setprecision(9);

    if (ans == 1e9)
        cout << -1 << endl;
    else
        cout << double(ans) << endl;
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