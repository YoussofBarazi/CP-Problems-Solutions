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

int n , k , mod = 1e9 + 7;
int a[N];
int mem[N][64];
bool vis[N][64];
bool ok[64];

int dp(int i , int AND)
{
    if (i == n)
        return ok[AND];

    int &ret = mem[i][AND];

    if (vis[i][AND])
        return ret;

    vis[i][AND] = true;

    ret = dp(i + 1 , AND & a[i]);

    if (ret >= mod)
        ret -= mod;
    
    ret += dp(i + 1 , AND);

    if (ret >= mod)
        ret -= mod;

    return ret;
}

void solve()
{
    cin >> n >> k;

    for (int i = 0 ; i < n ; i ++)
        cin >> a[i];

    for (int i = 0 ; i < n ; i ++)
        for (int j = 0 ; j < 64 ; j ++)
            mem[i][j] = 0 , vis[i][j] = false;

    for (int i = 0 ; i <= 63 ; i ++)
    {
        int cnt = 0;
        for (int j = 0 ; j < 6 ; j ++)
        {
            cnt += bool(i & (1 << j));
        }

        ok[i] = cnt == k;
    }

    cout << (dp(0 , 63) - (k == 6) + mod) % mod << endl;
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