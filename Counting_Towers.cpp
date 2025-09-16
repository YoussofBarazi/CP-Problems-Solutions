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

const int N = 1000009;

int n = N , mod = 1e9 + 7;
ll dp[3][N];

void solve()
{
    dp[1][1] = dp[2][1] = 1;

    for (int i = 2 ; i < n ; i ++)
    {
        dp[1][i] = (dp[1][i - 1] * 4 + dp[2][i - 1]) % mod;
        dp[2][i] = (dp[1][i - 1] + dp[2][i - 1] * 2) % mod;
    }
}

int main()
{
    // IO("name");
    IOS;
    
    solve();

    int t = 1;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << (dp[2][n] + dp[1][n]) % mod << endl;
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