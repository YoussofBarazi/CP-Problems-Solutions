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

const int N = 100009;

int k , mod = 1e9 + 7;
int dp[N];
int ans[N];

void solve()
{
    int a , b;
    cin >> a >> b;

    cout << (ans[b] - ans[a - 1] + mod) % mod << endl; 
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    cin >> t >> k;

    dp[0] = 1;

    for (int i = 1 ; i <= 1e5 ; i ++)
    {
        dp[i] = dp[i - 1];
        
        if (i >= k)
            dp[i] += dp[i - k];

        dp[i] %= mod;
    }

    for (int i = 1 ; i <= 1e5 ; i ++)
    {
        ans[i] += ans[i - 1] + dp[i];
        ans[i] %= mod;
    }

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