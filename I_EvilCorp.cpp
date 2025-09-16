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

const int N = 100009;

vector<int> adj[N];
int in[N], out[N], timer = 0;

void dfs_order(int u)
{
    in[u] = ++timer;

    for (auto v : adj[u])
        dfs_order(v);

    out[u] = timer;
}

ll lazy[N * 10 << 2], seg[N * 10 << 2];

void push(int p, int l, int r)
{
    if (lazy[p] == 0)
        return;

    seg[p] += lazy[p];

    if (l != r)
        lazy[p << 1] += lazy[p], lazy[p << 1 | 1] += lazy[p];

    lazy[p] = 0;
}

void update(int p, int l, int r, int i)
{
    push(p, l, r);

    if (l == r)
    {
        seg[p] = 0;
        return;
    }

    int m = l + (r - l) / 2;

    if (i <= m)
        update(p << 1, l, m, i);
    else
        update(p << 1 | 1, m + 1, r, i);
}

void range_update(int p, int l, int r, int s, int e, int val)
{
    push(p, l, r);

    if (s <= l && r <= e)
    {
        lazy[p] += val;
        push(p, l, r);
        return;
    }

    if (l > e || r < s)
        return;

    int m = l + (r - l) / 2;

    range_update(p << 1, l, m, s, e, val);
    range_update(p << 1 | 1, m + 1, r, s, e, val);
}

int get(int p, int l, int r, int i)
{
    push(p, l, r);

    if (l == r)
        return seg[p];

    int m = l + (r - l) / 2;

    if (i <= m)
        return get(p << 1, l, m, i);

    return get(p << 1 | 1, m + 1, r, i);
}

struct query
{
    int type, id, value;

    query(int t, int i, int v)
    {
        type = t;
        id = i;
        value = v;
    }
};

void solve()
{
    int n, s;
    cin >> n >> s;

    int ID = 1;
    vector<query> queries;
    for (int i = 0; i < n; i++)
    {
        int type, id, val = -1;
        cin >> type >> id;

        if (type == 1)
        {
            ID++;
            adj[id].pb(ID);
            queries.pb(query(type, ID, val));

            continue;
        }

        if (type == 2 || type == 3)
            cin >> val;

        queries.pb(query(type, id, val));
    }

    dfs_order(1);

    int size = ID;
    vector<ll> M(size + 1, s), ans(size + 1, 0);

    for (auto x : queries)
    {
        int t = x.type, u = x.id, val = x.value;

        if (t == 1)
        {
            update(1, 1, size, in[u]);
        }
        else if (t == 2)
        {
            ans[u] += M[u] * get(1, 1, size, in[u]);
            update(1, 1, size, in[u]);
            M[u] = val;
        }
        else if (t == 3)
        {
            range_update(1, 1, size, in[u], out[u], val);
        }
        else
        {
            cout << ans[u] + M[u] * get(1, 1, size, in[u]) << endl;
        }
    }
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