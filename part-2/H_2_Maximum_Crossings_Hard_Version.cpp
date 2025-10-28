#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

ll seg[4 * N];

void update(int vertix, int left, int right, int ndx)
{
    if (left == right)
    {
        seg[vertix]++;
        return;
    }

    int mid = left + (right - left) / 2;

    if (ndx <= mid)
        update(vertix * 2, left, mid, ndx);
    else
        update(vertix * 2 + 1, mid + 1, right, ndx);

    seg[vertix] = seg[vertix * 2] + seg[vertix * 2 + 1];
}

ll query(int vertix, int left, int right, int start, int end)
{
    if (start <= left && right <= end)
        return seg[vertix];

    if (right < start || left > end)
        return 0;

    int mid = left + (right - left) / 2;

    ll sum1 = query(vertix * 2, left, mid, start, end);

    ll sum2 = query(vertix * 2 + 1, mid + 1, right, start, end);

    return sum1 + sum2;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i <= 4 * n; i++)
        seg[i] = 0;

    ll ans = 0;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        ans += query(1, 1, n, a[i], n);

        update(1, 1, n, a[i]);
    }

    cout << ans << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "")
{

    cin.tie(0)->sync_with_stdio(0);
    if (name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}