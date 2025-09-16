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
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 100009;

ll seg[4 * N], a[N];

void build(int p, int l, int r)
{
    if (l == r)
    {
        seg[p] = a[l];
        return;
    }

    int mid = l + (r - l) / 2;

    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);

    seg[p] = gcd(seg[p * 2], seg[p * 2 + 1]);
}

ll query(int p, int l, int r, int S, int E)
{
    if (S <= l && r <= E)
        return seg[p];

    if (S > r || E < l)
        return 0;

    int mid = l + (r - l) / 2;

    ll q1 = query(p * 2, l, mid, S, E);
    ll q2 = query(p * 2 + 1, mid + 1, r, S, E);

    return gcd(q1, q2);
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    build(1, 1, n);

    int r = 1, ans = 1e9;

    for (int l = 1; l <= n; l++)
    {
        int gcd = query(1, 1, n, l, r);

        while (r <= n && gcd != 1)
            r++, gcd = query(1, 1, n, l, r);

        if (gcd == 1)
            ans = min(ans, r - l + 1);
    }

    if (ans != 1e9)
        cout << ans << endl;
    else
        cout << -1 << endl;
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