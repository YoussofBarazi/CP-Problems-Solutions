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

ll a[N];
vector<int> adj[N];

ll dfs(int u)
{
    if (adj[u].size() == 0)
    {
        return a[u];
    }

    ll cnt = a[u], c = adj[u].size();

    if (adj[u].size() == 1)
    {
        a[adj[u].back()] += cnt;

        return dfs(adj[u].back());
    }

    priority_queue<ll> mx;

    for (auto v : adj[u])
    {
        cnt += a[v];
        mx.push(a[v]);
    }

    ll x;

    while (mx.size())
    {
        x = mx.top();

        if (x * c <= cnt)
        {
            break;
        }

        mx.pop();
        cnt -= x;
        c--;
    }

    for (auto v : adj[u])
    {
        a[v] = max((cnt + c - 1) / c , a[v]);
    }

    a[u] = 0;

    ll ans = 0;

    for (auto v : adj[u])
    {
        ans = max(ans , dfs(v));
    }

    return ans ;
}

void solve()
{
    int n;
    cin >> n;

    for (int v = 2; v <= n; v++)
    {
        int u;
        cin >> u;

        adj[u].push_back(v);
    }

    for (int i = 1 ; i <= n; i++)
    {
        cin >> a[i];
    }

    cout << dfs(1) << endl;
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

void IO(string name = "")
{

    cin.tie(0)->sync_with_stdio(0);
    if (name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}