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

vector<pl> adj[N];
bool included[N];

ll MST(int u)
{
    priority_queue<pl, vector<pl>, greater<pl>> q;

    q.push({0, u});

    ll ans = 0;

    while (!q.empty())
    {
        pl p = q.top();
        q.pop();

        if (included[p.S])
            continue;

        included[p.S] = true;

        ans += p.F;

        for (auto v : adj[p.S])
        {
            if (included[v.S])
                continue;

            q.push(v);
        }
    }

    return ans;
}

void solve()
{
    int n, m, p;
    cin >> p >> n >> m;

    for (int i = 0; i <= n; i++)
        adj[i].resize(0);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].pb({w * p, v});
        adj[v].pb({w * p, u});
    }

    cout << MST(1) << endl;
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