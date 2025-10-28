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

const int N = 500009;

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
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        parent[i] = i, Size[i] = 1;
    }

    vector<int> ind(m + 1, -1);
    vector<int> a;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        a.pb(x);
    }

    sort(all(a));

    ll ans = 0;

    ind[a[n - 1]] = n - 1;
    for (int i = 0; i < n - 1; i++)
    {
        ind[a[i]] = i;
        if (a[i] == a[i + 1])
        {
            ans += a[i];
            join(i + 1, i);
        }
    }

    vector<vector<int>> GCD(m + 1);

    for (int d = 1; d <= m; d++)
    {
        for (int i = d; i <= m; i += d)
        {
            if (ind[i] != -1)
                GCD[d].pb(ind[i]);
        }
    }

    for (int d = m; d >= 1; d--)
    {
        if (GCD[d].size() <= 1)
        {
            continue;
        }

        int u = GCD[d].back();

        for (auto v : GCD[d])
        {
            if (join(u, v))
            {
                ans += d;
            }
        }
    }

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