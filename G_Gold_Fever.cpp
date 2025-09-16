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

int seg[N * 2], g[N], a[N], b[N];

void update(int p, int l, int r, int i, int v)
{
    if (l == r)
    {
        seg[p] = v;
        return;
    }

    int mid = l + (r - l) / 2;

    if (mid >= i)
        update(p * 2, l, mid, i, v);
    else
        update(p * 2 + 1, mid + 1, r, i, v);

    seg[p] = max(seg[p * 2], seg[p * 2 + 1]);
}

int query(int p, int l, int r, int S, int E)
{
    if (S <= l && r <= E)
        return seg[p];

    if (S > r || l > E)
        return 0;

    int mid = l + (r - l) / 2;

    return max(query(p * 2, l, mid, S, E), query(p * 2 + 1, mid + 1, r, S, E));
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> g[i] >> a[i] >> b[i];

    int ans = 0;

    for (int i = n; i >= 1; i--)
    {
        int l = i + a[i];
        int r = i + b[i];

        int v = query(1, 1, n, l, r) + g[i];
        update(1, 1, n, i, v);

        ans = max(ans, v);
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