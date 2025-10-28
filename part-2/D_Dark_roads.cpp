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

ll Prim_MST(int u)
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

void solve(int n, int m)
{
    for (int i = 0; i <= n; i++)
        adj[i].clear(), included[i] = false;

    int cost = 0;

    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        adj[x].pb({z, y});
        adj[y].pb({z, x});

        cost += z;
    }

    cout << cost - Prim_MST(1) << endl;
}

int main()
{
    IOS;

    int n, m;
    cin >> n >> m;

    while (n != 0 && m != 0)
    {
        solve(n, m);
        cin >> n >> m;
    }

    return 0;
}