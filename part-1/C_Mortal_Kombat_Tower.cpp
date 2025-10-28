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

int n;
int a[N];
int mem[N][3];
bool vis[N][3];

int dp(int i , int t)
{
    if (i >= n)
        return 0;

    int &ret = mem[i][t];

    if (vis[i][t])
        return ret;

    vis[i][t] = true;

    if (t)
    {
        ret = min(dp(i + 1 , 0) + a[i] , dp(i + 2 , 0) + a[i] + a[i + 1]);
    }
    else 
    {
        ret = min(dp(i + 1 , 1) , dp(i + 2 , 1));
    }

    return ret;
}

void solve()
{
    cin >> n ;

    for (int i = 0 ; i <= n ; i ++)
        a[i] = vis[i][0] = vis[i][1] = false;

    for (int i = 0 ; i < n ; i ++)
        cin >> a[i];

    cout << dp(0 , 1) << endl;
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