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

const int N = 200009;

vector <int> adj[N];
vector <bool> vis(N , false);
vector <ll> a(N);
int n , k , p1 , p2;
ll ans = 0;

void dfs(int u , int cnt , ll cur)
{
    if (cnt == k)
        return ;

    vis[u] = true;

    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v , cnt + 1 , cur + a[u]);
        }
        ans = max(ans , cur + (k - cnt) * a[u]);
    }
}

void solve()
{
    cin >> n >> k >> p1 >> p2;

    p1 -- , p2 --;

    vector <int> p(n);
    for (int i = 0 ; i < n ; i ++)
    {
        cin >> p[i];
        p[i] --;

        adj[i].pb(p[i]);
    }

    for (int i = 0 ; i < n ; i ++)
        cin >> a[i];

    dfs(p1 , 0 , 0);
    ll ansB = ans;
    
    for (int i = 0 ; i < n ; i ++)
        vis[i] = false;

    ans = 0;
    dfs(p2 , 0 , 0);
    ll ansS = ans;

    //cout << ansB << " " << ansS << endl;
    
    if (ansB > ansS)
        cout << "Bodya" << endl;
    else if (ansB < ansS)   
        cout << "Sasha" << endl;
    else 
        cout << "Draw" << endl; 
    
    for (int i = 0 ; i < n ; i ++)
    {
        vis[i] = false;
        adj[i].clear();
    }
    ans = 0;
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

void IO(string name = "") {

	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}

}