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

const int N = 109;

int adj[N][N];

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    vector<int> ans(n + 1, 0);

    ans[1] = 1;
    for (int j = 1; j <= n; j++)
    {
        vector<bool> valid(5, true);

        for (int k = 1; k <= n; k++)
        {
            if (adj[j][k])
                valid[ans[k]] = false;
        }

        int type = 1;
        while (!valid[type])
            type++;

        ans[j] = type;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i];
    cout << endl;
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