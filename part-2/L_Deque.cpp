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

const int N = 3009;

int n;
ll a[N];
ll mem[N][N][2];
bool vis[N][N][2];

ll dp(int l , int r , int t)
{
    if (l > r)
        return 0;
    
    ll &ret = mem[l][r][t];

    if (vis[l][r][t])
        return ret;

    vis[l][r][t] = true;

    if (t)
        ret = min(dp(l + 1 , r , !t) - a[l] , dp(l , r - 1 , !t) - a[r]);
    else 
        ret = max(dp(l + 1 , r , !t) + a[l] , dp(l , r - 1 , !t) + a[r]);

    return ret;
}

void solve()
{
    cin >> n;

    for (int i = 0 ; i < n ; i ++)
        cin >> a[i];
    
    cout << dp(0 , n - 1 , 0);
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