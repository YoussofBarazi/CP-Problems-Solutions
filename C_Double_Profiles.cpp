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

ll b1 = 1000001, b2 = 1000003, mod1 = 1e9 + 7, mod2 = 998244353;

pair<ll, ll> get(vector<ll> &a)
{
    ll ans1 = 0, ans2 = 0;
    for (ll x : a)
    {
        ans1 = (b1 * ans1 % mod1 + x) % mod1;
        ans2 = (b2 * ans1 % mod2 + x) % mod2;
    }

    return {ans1, ans2};
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    unordered_map<ll, ll> freq;

    for (int i = 1; i <= n; i++)
    {
        sort(all(adj[i]));
        pair<ll, ll> x = get(adj[i]);
        ll v = (x.F * b1 + x.S);

        freq[v]++;

        adj[i].pb(i);

        sort(all(adj[i]));
        x = get(adj[i]);
        v = (x.F * b1 + x.S);

        freq[v]++;
    }

    ll ans = 0;
    for (auto x : freq)
    {
        ans += (x.S - 1) * x.S / 2;
    }

    cout << ans << endl;
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