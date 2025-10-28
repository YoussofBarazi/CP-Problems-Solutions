#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7;

vector<int> adj[N];
vector<bool> vis(N, false);
vector<int> col(N, 0);
string s;
int ans = 0;

void dfs(int u)
{
    vis[u] = true;
    col[u] = 1;

    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
        else if (col[v] == 1)
        {
            ans = -1;
            return;
        }
    }

    col[u] = 2;
}

int freq[N][26];
vector<int> deg(N, 0);

void calc(int u)
{
    vis[u] = true;

    if (u)
        freq[u][s[u - 1] - 'a']++;

    vector <int> f(26 , 0);

    for (int v : adj[u])
    {
        if (!vis[v])
        {
            calc(v);
        }

        for (int i = 0 ; i < 26 ; i ++)
        {
            f[i] = max(freq[v][i] , f[i]);
        }
    }
    
    for (int i = 0; i < 26; i++)
        freq[u][i] += f[i] , ans = max(ans, freq[u][i]);
}

int main()
{
    int n, m;
    cin >> n >> m;

    cin >> s;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        deg[v]++;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
        if (!col[i])
            dfs(i);

    if (ans == -1)
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
            adj[0].push_back(i);

    vis.assign(n + 1, false);

    calc(0);

    cout << ans << endl;

    return 0;
}
