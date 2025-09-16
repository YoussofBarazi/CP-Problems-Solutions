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

void init(int n)
{
    for (int i = 0 ; i <= n ; i ++)
        parent[i] = i , Size[i] = 1;
}

void solve()
{
    int n , m;
    cin >> n >> m;

    vector <pll> a(n);
    vector <pair<ll , pll>> edges;

    init(n);

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> a[i].F;
        a[i].S = i + 1;
    }

    sort(all(a));

    for (int i = 1 ; i < n ; i ++)
        edges.pb({a[i].F + a[0].F , {a[0].S , a[i].S}});

    for (int i = 0 ; i < m ; i ++)
    {
        ll u , v , w;
        cin >> u >> v >> w;

        edges.pb({w , {u , v}});
    }

    sort(all(edges));

    ll ans = 0;

    for (auto e : edges)
    {
        if (join(e.S.F , e.S.S))
            ans += e.F;
    }

    cout << ans << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "") {

	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}

}