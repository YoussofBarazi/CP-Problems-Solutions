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

const int N = 1009;

int h , w;
ll mem[N][N];
vector <string> s(N);
bool vis[N][N];
ll mod = 1e9 + 7;

ll dp(int i , int j)
{
    if (i == h - 1 && j == w - 1)
        return 1;
    
    if (i < 0 || j < 0 || i == h || j == w || s[i][j] == '#')
        return 0;

    ll &ret = mem[i][j];

    if (vis[i][j])
        return ret;

    vis[i][j] = true;

    ret = dp(i + 1 , j) + dp(i , j + 1);
    ret %= mod;

    return ret;
}

void solve()
{
    cin >> h >> w;

    for (int i = 0 ; i < h ; i ++)
        cin >> s[i];

    cout << dp(0 , 0) << endl;
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