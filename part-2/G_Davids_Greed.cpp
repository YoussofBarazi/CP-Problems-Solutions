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

ll mod = 1e9 + 7, c = 1;
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

    Size[a] += Size[b];

    return true;
}

void solve()
{
    int n, p;
    cin >> n >> p;

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        Size[i] = 1;
    }

    vector<pi> a(n);
    for (auto &w : a)
        cin >> w.F >> w.S;

    ll cost = 0;
    vector<pair<ll, pi>> edges;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll w = ceil(sqrt((a[i].F - a[j].F) * (a[i].F - a[j].F) + (a[i].S - a[j].S) * (a[i].S - a[j].S)) * p);
            edges.pb({w, {i, j}});
        }
    }

    sort(all(edges));

    for (auto e : edges)
    {
        if (join(e.S.F, e.S.S))
        {
            cost += e.F;
            cost %= mod;
        }
    }

    cout << "Scenario #" << c++ << ": "
         << cost << endl;
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