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

const int N = 501;

int dp[N][N];

void solve()
{
    int a , b;
    cin >> a >> b;

    for (int i = 0 ; i < N ; i ++)
        for (int j = 0 ; j < N ; j ++)
            dp[i][j] = 1e9;

    for (int i = 0 ; i < N ; i ++)
        dp[i][i] = 0;

    for (int i = 1 ; i <= a ; i ++)
    {
        for (int j = 1 ; j <= b ; j ++)
        {
            for (int k = 1 ; k <= max(a , b) ; k ++)
            {
                if (i - k >= 0)
                    dp[i][j] = min(dp[i][j] , dp[i - k][j] + dp[k][j] + 1);
                if (j - k >= 0)
                    dp[i][j] = min(dp[i][j] , dp[i][j - k] + dp[i][k] + 1);
            }
        }
    }
    cout << dp[a][b] << endl;
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