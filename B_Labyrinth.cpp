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

const int N = 2009;

int n , m , r , c , x , y;

vector <string> s(N);
vector <int> L[N];
vector <bool> vis[N];

int di[] = {-1 , 0 , 1 , 0};
int dj[] = {0 , 1 , 0 , -1};

void BFS(int i , int j)
{
    deque <pii> q;
    q.push_back({i , j});
    
    L[i][j] = 0;

    while(!q.empty())
    {
        pii u = q.front();
        q.pop_front();
        
        int O_O = u.J - j;

        if (vis[u.I][u.J] || L[u.I][u.J] > x || O_O + L[u.I][u.J] > y)
            continue;
        
        vis[u.I][u.J] = true;

        for (int t = 0 ; t < 4 ; t ++)
        {
            int i = u.I + di[t] , j = u.J + dj[t];

            if (i < 0 || i >= n || j < 0 || j >= m || s[i][j] == '*')
                continue;

            L[i][j] = min(L[i][j] , L[u.I][u.J] + (t == 3));

            if (t != 3) q.push_front({i , j});
            else q.push_back({i , j});
        }
    }
}

void solve()
{
    cin >> n >> m >> r >> c >> x >> y;

    r -- , c --;

    for (int i = 0 ; i < n ; i ++)
    {    
        cin >> s[i];
        vis[i].resize(m , false);
        L[i].resize(m , 1e9);
    }

    BFS(r , c);
    
    int cnt = 0;

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = 0 ; j < m ; j ++)
        {
            cnt += vis[i][j];
        }
    }

    cout << cnt << endl;
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