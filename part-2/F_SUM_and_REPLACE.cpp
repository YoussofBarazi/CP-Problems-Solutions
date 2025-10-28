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

const int N = 300009;

int D[1000001];

void precalc()
{
    for (int i = 1; i < 1000001; i++)
    {
        for (int j = i; j < 1000001; j += i)
        {
            D[j]++;
        }
    }
}

ll st[4 * N], a[N];

void merge(int vertix, int left, int right)
{
    st[vertix] = st[left] + st[right];
}

void build(int vertix, int left, int right)
{
    if (left == right)
    {
        st[vertix] = a[left];
        return;
    }

    int mid = left + (right - left) / 2;

    build(vertix * 2, left, mid);
    build(vertix * 2 + 1, mid + 1, right);

    merge(vertix, vertix * 2, vertix * 2 + 1);
}

void update(int vertix, int left, int right, int ndx, int value)
{
    if (left == right)
    {
        st[vertix] = value;
        return;
    }

    int mid = left + (right - left) / 2;

    if (ndx <= mid)
        update(vertix * 2, left, mid, ndx, value);
    else
        update(vertix * 2 + 1, mid + 1, right, ndx, value);

    merge(vertix, vertix * 2, vertix * 2 + 1);
}

ll query(int vertix, int left, int right, int start, int end)
{
    if (start <= left && right <= end)
        return st[vertix];

    if (right < start || left > end)
        return 0;

    int mid = left + (right - left) / 2;

    ll sum1 = query(vertix * 2, left, mid, start, end);
    ll sum2 = query(vertix * 2 + 1, mid + 1, right, start, end);

    return sum1 + sum2;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s.insert(i);
    }

    build(1, 1, n);
    precalc();

    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 2)
        {
            cout << query(1, 1, n, l, r) << endl;
            continue;
        }

        auto L = s.lower_bound(l);

        vector<int> del;

        while (*L <= r && L != s.end())
        {
            a[*L] = D[a[*L]];

            update(1, 1, n, *L, a[*L]);

            if (a[*L] <= 2)
                del.push_back(*L);

            L++;
        }

        for (auto x : del)
            s.erase(x);
    }
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