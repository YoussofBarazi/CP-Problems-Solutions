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

int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    vector <string> s(n);
    for (auto &x : s)
        cin >> x;

    vector <vector<int>> dp(n , vector<int>(n , 0));
    dp[0][0] = s[0][0] != '*';

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = 0 ; j < n ; j ++)
        {
            if (s[i][j] == '*' || (i == 0 && j == 0))
                continue;

            if (i - 1 >= 0 && s[i - 1][j] != '*')
                dp[i][j] += dp[i - 1][j] % mod;
            
            if (j - 1 >= 0 && s[i][j - 1] != '*')
                dp[i][j] += dp[i][j - 1] % mod;

            dp[i][j] %= mod;
        }
    }

    cout << dp[n - 1][n - 1] << endl;
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