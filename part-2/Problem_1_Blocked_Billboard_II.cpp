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

bool isIn(int x, int y, int x1, int y1, int x2, int y2)
{
    return x1 <= x && x <= x2 && y1 <= y && y <= y2;
}

void solve()
{
    int x1, x2, y1, y2, x3, y3, x4, y4;

    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    scanf("%d%d%d%d", &x3, &y3, &x4, &y4);

    int ans = (x2 - x1) * (y2 - y1);

    int w = min(x2, x4) - max(x1, x3);
    int h = min(y2, y4) - max(y1, y3);

    int cnt = 0;

    cnt += isIn(x1, y1, x3, y3, x4, y4);
    cnt += isIn(x2, y2, x3, y3, x4, y4);
    cnt += isIn(x1, y2, x3, y3, x4, y4);
    cnt += isIn(x2, y1, x3, y3, x4, y4);

    if (cnt >= 3)
        ans = 0;
    else if (cnt == 2)
        ans -= w * h;

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