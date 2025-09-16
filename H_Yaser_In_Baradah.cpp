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

ll st[4 * N], a[N];

void merge(int vertix, int left, int right)
{
    st[vertix] = max(st[left], st[right]);
}

void build(int vertix, int left, int right)
{
    if (left == right) // base case : single element in the segment
    {
        st[vertix] = a[left];
        return;
    }

    int mid = left + (right - left) / 2; // deviding the segment

    build(vertix * 2, left, mid);          // left segment
    build(vertix * 2 + 1, mid + 1, right); // right segment

    merge(vertix, vertix * 2, vertix * 2 + 1);
}

void update(int vertix, int left, int right, int ndx, ll value)
{
    if (left == right) // base case : single element in the segment
    {
        st[vertix] += value;
        return;
    }

    int mid = left + (right - left) / 2; // deviding the segment

    if (ndx <= mid)
        update(vertix * 2, left, mid, ndx, value); // left segment
    else
        update(vertix * 2 + 1, mid + 1, right, ndx, value); // right segment

    merge(vertix, vertix * 2, vertix * 2 + 1);
}

void solve()
{
    int n;
    cin >> n;

    set<int> exist;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        exist.insert(i);
    }

    build(1, 1, n);

    int q;
    cin >> q;

    cout << st[1] << endl;

    while (q--)
    {
        ll s;
        cin >> s;

        auto x = exist.end();
        ll v = a[s];

        if (exist.count(s))
        {
            exist.erase(s);
            update(1, 1, n, s, -v);
            a[s] = 0;
        }

        x = exist.lower_bound(s);

        if (x != exist.end())
        {
            update(1, 1, n, *x, v);
            a[*x] += v;
        }

        cout << st[1] << endl;
    }
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