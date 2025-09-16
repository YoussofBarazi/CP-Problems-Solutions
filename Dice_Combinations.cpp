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

int n , mod = 1e9 + 7;
bool vis[N];
ll dp[N];

ll f(int i)
{
    if (i > n)
        return 0;
    if (i == n)
        return 1;

    if (vis[i])
        return dp[i];

    vis[i] = true;

    for (int d = 1 ; d <= 6 ; d ++)
        dp[i] = (dp[i] + f(i + d)) % mod; 

    return dp[i];
}

void solve()
{
    cin >> n;

    cout << f(0) << endl;
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