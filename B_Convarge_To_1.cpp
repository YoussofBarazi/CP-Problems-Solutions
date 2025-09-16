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

const int N = 1000001;

vector<int> GPF(1e6 + 1);
vector<int> adj[N];

void calc()
{
    for (int i = 2; i < GPF.size(); i++)
    {
        if (GPF[i] == 0)
            for (int j = i; j < GPF.size(); j += i)
                GPF[j] = i;
    }
}

int a[N], seg[N << 2];

void build(int p, int l, int r)
{
    if (l == r)
    {
        seg[p] = a[l];
        return;
    }

    int m = l + (r - l) / 2;

    build(p << 1, l, m);
    build(p << 1 | 1, m + 1, r);

    seg[p] = max(seg[p << 1], seg[p << 1 | 1]);
}

int query(int p, int l, int r, int s, int e)
{
    if (s <= l && r <= e)
        return seg[p];

    if (l > e || s > r)
        return 0;

    int m = l + (r - l) / 2;

    int mx1 = query(p << 1, l, m, s, e);
    int mx2 = query(p << 1 | 1, m + 1, r, s, e);

    return max(mx1, mx2);
}

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);

    priority_queue<int> q;
    vector<int> freq(N, 0);
    vector<bool> done(N, false);

    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);

        if (x == 1)
            continue;

        if (freq[x] == 0)
            q.push(x);

        freq[x]++;

        while (x != GPF[x])
            x /= GPF[x];

        adj[x].pb(i);
    }

    int cnt = 0;

    while (q.size())
    {
        int x = q.top();
        q.pop();

        if (done[x])
            continue;
        done[x] = true;

        if (GPF[x] == x)
        {
            for (auto w : adj[x])
                a[w] = ++cnt;
        }
        else
        {
            freq[x / GPF[x]] += freq[x];
            cnt += freq[x];
            x /= GPF[x];
            q.push(x);
        }
    }

    build(1, 1, n);

    while (m--)
    {
        int l, r;
        scanf("%d %d", &l, &r);

        printf("%d\n", query(1, 1, n, l, r));
    }
}

int main()
{
    IOS;

    calc();

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}