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

int h[N];
int dp[N];
int n , k;

void solve()
{
    cin >> n >> k;

    for (int i = 0 ; i < n ; i ++)
        cin >> h[i];

    for (int i = 1 ; i < n ; i ++)
        dp[i] = 1e9;

    for (int i = 0 ; i < n ; i ++)
    { 
        for (int j = 1 ; j <= k ; j ++)
            if (i + j < n)
                dp[i + j] = min(dp[i + j] , dp[i] + abs(h[i] - h[i + j]));
    }

    cout << dp[n - 1] << endl;
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