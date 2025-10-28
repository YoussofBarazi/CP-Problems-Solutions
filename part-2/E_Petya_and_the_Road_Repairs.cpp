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

int parent[N], milkMan[N];

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

    if (milkMan[b])
        swap(a, b);

    parent[b] = a;

    return true;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> milkMan[i];

        parent[i] = i;
    }

    vector<pair<int, pi>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges.pb({w, {u, v}});
    }

    sort(all(edges));

    ll cost = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].S.F, v = edges[i].S.S, w = edges[i].F;
        if (!(milkMan[get(u)] && milkMan[get(v)]) && join(u, v))
            cost += w;
    }

    bool impossible = false;
    for (int i = 1; i <= n; i++)
    {
        impossible |= !milkMan[get(i)];
    }

    if (impossible)
        cout << "impossible" << endl;
    else
        cout << cost << endl;
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