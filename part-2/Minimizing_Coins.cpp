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

int n , x , c[100];
int dp[int(1e6 + 7)];
bool vis[int(1e6 + 7)];

int f(int sum)
{
    if (sum > x)
        return x + 10;
    if (sum == x)
        return 0;

    if (vis[sum])
        return dp[sum];

    vis[sum] = true;

    for (int i = 0 ; i < n ; i ++)
        dp[sum] = min(dp[sum] , f(sum + c[i]) + 1);

    return dp[sum];
}

void solve()
{
    cin >> n >> x;

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> c[i];
    }

    for (int i = 0 ; i <= x ; i ++)
        dp[i] = x + 10;

    int ans = f(0);
    
    if (ans <= x)
        cout << ans << endl;
    else
        cout << -1 << endl;
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