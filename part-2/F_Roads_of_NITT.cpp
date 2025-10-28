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

int ans;

int parent[N], Size[N];

int get(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = get(parent[v]);
}

bool join(int a, int b)
{
    a = get(a);
    b = get(b);

    if (a == b)
        return false;

    if (Size[a] < Size[b])
        swap(a, b);

    parent[b] = a;

    ans -= Size[a] * Size[b];

    Size[a] += Size[b];

    return true;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        Size[i] = 1;
    }

    ans = n * (n - 1) / 2;

    vector<pi> edges(n);
    for (int i = 1; i < n; i++)
    {
        cin >> edges[i].F >> edges[i].S;
    }

    int m;
    cin >> m;
    vector<pi> query;
    vector<bool> del(n, false);

    for (int i = 0; i < m; i++)
    {
        char t;
        int x = 0;
        cin >> t;

        if (t == 'R')
            cin >> x;

        del[x] = true;
        query.pb({t == 'R', x});
    }

    for (int i = 1; i < n; i++)
    {
        if (!del[i])
            join(edges[i].F, edges[i].S);
    }

    reverse(all(query));

    vector<int> x;

    for (int i = 0; i < m; i++)
    {
        if (query[i].F)
            join(edges[query[i].S].F, edges[query[i].S].S);
        else
            x.pb(ans);
    }

    reverse(all(x));

    for (auto ans : x)
        cout << ans << endl;
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