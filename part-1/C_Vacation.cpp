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
int H[N][4];
int dp[N][4];

void solve()
{
    cin >> n;

    for (int i = 0 ; i < n ; i ++)
        for (int j = 0 ; j < 3 ; j ++)
            cin >> H[i][j];

    int ans = 0;
    for (int j = 0 ; j < 3 ; j ++)
        dp[0][j] = H[0][j] , ans = max(ans , dp[0][j]);

    for (int i = 1 ; i < n; i ++)
    {
        for (int j = 0 ; j < 3 ; j ++)
        {
            for (int k = 0 ; k < 3 ; k ++)
            {
                if (j != k)
                    dp[i][j] = max(H[i][j] + dp[i - 1][k] , dp[i][j]); 
            }      

            ans = max(dp[i][j] , ans);
        }
    }

    cout << ans << endl;
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