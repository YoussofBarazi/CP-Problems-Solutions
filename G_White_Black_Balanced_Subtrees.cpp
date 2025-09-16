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

const int N = 10009;

string s;
vector<int> adj[N];
int black[N], white[N];

void dfs(int u)
{
    black[u] += s[u - 1] == 'B';
    white[u] += s[u - 1] == 'W';

    for (auto v : adj[u])
    {
        dfs(v);

        black[u] += black[v];
        white[u] += white[v];
    }
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
        white[i] = black[i] = 0;
    }

    for (int v = 2; v <= n; v++)
    {
        int u;
        cin >> u;

        adj[u].pb(v);
    }
    
    cin >> s;

    dfs(1);

    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        cnt += black[i] == white[i];
    }

    cout << cnt << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    cin >> t;

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