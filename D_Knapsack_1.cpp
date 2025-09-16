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

const int NN = 200009;

int N , W;
int w[108] , v[108];
ll dp[108][NN];

void solve()
{
    cin >> N >> W;

    for (int i = 1 ; i <= N ; i ++)
        cin >> w[i] >> v[i];

    ll ans = 0;

    for (int i = 1 ; i <= N ; i ++)
    {
        for (int j = 1 ; j <= W ; j ++)
        {
            dp[i][j] = dp[i - 1][j];

            if (w[i] <= j)
                dp[i][j] = max(dp[i][j] , dp[i - 1][j - w[i]] + v[i]);
            
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