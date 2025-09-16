#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define Endl endl
#define ll long long
#define in insert
#define F first
#define S second
#define py() printf("YES\n")
#define pn() printf("NO\n")
#define loop(i, n) for (int i = 0; i < n; i++)
#define lop(i, x, n) for (int i = x; i <= n; i++)
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

const int N = 300005;

int n, m, x, y;
double c;
double dis[N];

vector<vector<pair<int, double>>> adj(N);

void djk()
{
    for (int i = 0; i <= n; i++)
        dis[i] = 1e7;

    dis[1] = 0;

    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    pq.push({dis[1], 1});

    while (!pq.empty())
    {
        double d = pq.top().F;
        int u = pq.top().S;
        pq.pop();

        for (auto i : adj[u])
        {
            double w = i.S;
            int v = i.F;

            double tmp = d + w;

            if (dis[v] - tmp > 0.00000001)
            {
                dis[v] = tmp;
                pq.push({dis[v], v});
            }
        }
    }
}

void solve()
{

    scanf("%d%d", &n, &m);
    loop(i, m)
    {
        scanf("%d%d%lf", &x, &y, &c);
        adj[x].pb({y, log(c)});
        adj[y].pb({x, log(c)});
    }

    djk();

    cout << fixed << setprecision(15) << dis[n] / log(7) << endl;
}

int main()
{

    int tt = 1;
    while (tt--)
    {
        solve();
    }

    return 0;
}