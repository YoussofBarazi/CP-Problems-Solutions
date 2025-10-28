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
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;

    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    scanf("%d%d%d%d", &x3, &y3, &x4, &y4);
    scanf("%d%d%d%d", &x5, &y5, &x6, &y6);

    int ans = (x2 - x1) * (y2 - y1) + (x4 - x3) * (y4 - y3);

    int w = min(x2, x6) - max(x1, x5);
    int h = min(y2, y6) - max(y1, y5);

    if (h > 0 && w > 0)
        ans -= h * w;

    w = min(x4, x6) - max(x3, x5);
    h = min(y4, y6) - max(y3, y5);

    if (h > 0 && w > 0)
        ans -= h * w;

    printf("%d\n", ans);
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