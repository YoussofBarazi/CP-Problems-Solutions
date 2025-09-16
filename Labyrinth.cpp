#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define I first
#define J second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 1009;

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

int n , m;
vector <string> s(N);
vector <bool> vis[N];
vector <int> dist[N];
vector <pii> parent[N];

void BFS(int i , int j)
{
    queue <pii> q;
    q.push({i , j});
    dist[i][j] = 0;

    while (!q.empty())
    {
        int i = q.front().I;
        int j = q.front().J;

        q.pop();

        if (vis[i][j])
            continue;

        vis[i][j] = true;

        for (int t = 0 ; t < 4 ; t ++)
        {
            int ni = i + dx[t] , nj = j + dy[t];

            if (ni < 0 || ni >= n || nj < 0 || nj >= m || s[ni][nj] == '#')
                continue;

            if (dist[i][j] + 1 < dist[ni][nj])
                parent[ni][nj] = {i , j} , dist[ni][nj] = dist[i][j] + 1;
            
            q.push({ni , nj});
        }
    }
}

void solve()
{
    cin >> n >> m;

    int sx , sy , ex , ey;

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> s[i];
    
        for (int j = 0 ; j < m ; j ++)
            if (s[i][j] == 'A')
                sx = i , sy = j;
            else if (s[i][j] == 'B')
                ex = i , ey = j;

        dist[i].resize(m , 1e9);
        vis[i].resize(m , false);
        parent[i].resize(m , {-1 , -1});
    }

    BFS(sx , sy);

    if (!vis[ex][ey])
    {
        cout << "NO" << endl;
        return ;
    }

    int i = ex , j = ey;
    string path = "" , dir = "URDL";

    while (i != -1)
    {
        pii u = parent[i][j];

        for (int t = 0 ; t < 4 ; t ++)
        {
            pii w = {i - dx[t] , j - dy[t]};

            if(w == parent[i][j])
                path.push_back(dir[t]);
        }

        i = u.I;
        j = u.J;   
    }

    reverse(all(path));

    cout << "YES\n" << path.size() << endl << path << endl; 
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

void IO(string name = "") {

	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}

}