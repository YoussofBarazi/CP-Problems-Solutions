#include <bits/stdc++.h>

#define F first
#define S second
#define ll long long
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 200009;

void solve()
{
    int n , r , m;
    cin >> n >> r >> m;

    vector <vi> adj(n + 1);

    for (int i = 0 ; i < r ; i ++)
    {
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector <int> gaurd(n + 1 , -1);
    vector <int> p(m + 1 , 0);

    for (int i = 1 ; i <= m ; i ++)
    {
        int k , s;
        cin >> k >> s;

        gaurd[k] = i;
        p[i] = s;  
    }
    vector <bool> vis(n + 1 , false);
    for (int i = 1 ; i <= n ; i ++)
    {
        if (gaurd[i] == -1 || vis[i])
            continue;

        int t = p[gaurd[i]];
        queue <pii> q;
        q.push({i , 0});

        while (!q.empty())
        {
            int u = q.front().F;
            int d = q.front().S;
            q.pop();

            if (d == t || vis[u])
            {
                vis[u] = true;
                continue;
            }   

            vis[u] = true;

            for (auto v : adj[u])
            {    
                if (gaurd[v] > 0 && gaurd[v] != gaurd[u])
                {    
                    cout << "No" << endl;
                    return ;
                }

                q.push({v , d + 1});
                gaurd[v] = gaurd[u];
            }
        }
    }

    for (int i = 1 ; i <= n ; i ++)
    {
        if (gaurd[i] == -1)
        {
            cout << "No" << endl;
            return ;
        }
    }
    cout << "Yes" << endl;
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