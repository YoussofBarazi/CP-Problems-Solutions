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

const int N = 300009;

vector <int> adj[N];

bool O_O(int a , int b , int c)
{
    queue <int> q;
    int v = 1;
    q.push(0);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (a > 0)
        {
            adj[u].push_back(v);
            q.push(v ++);
            adj[u].push_back(v);
            q.push(v ++);
            a --;
        }
        else if (b > 0)
        {
            adj[u].push_back(v);
            q.push(v ++);
            b --;
        }
        else if (c > 0)
        {
            c --;
        }
        else return false;
    }

    return a == 0 && b == 0 && c == 0 && v != a + b + c;
}

int dfs(int u)
{
    int d = 0;

    for (auto v : adj[u])
    {
        d = max(dfs(v) + 1 , d);
    }    

    return d;
}

void solve()
{
    int a , b , c;
    cin >> a >> b >> c;

    for (int i = 0 ; i < a + b + c ; i ++)
        adj[i].clear();

    if (O_O(a , b , c))
        cout << dfs(0) << endl;
    else 
        cout << -1 << endl;

    // for (int i = 0 ; i < a + b + c ; i ++)
    // {
    //     cout << i << " has :\n";
    //     for (auto j : adj[i])
    //         cout << j << " ";
    //     cout << endl;
    // }
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