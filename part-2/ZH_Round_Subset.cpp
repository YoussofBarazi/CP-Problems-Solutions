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

const int N = 209;

ll a[N];
int n , K;
int freq2[N] , freq5[N];
int dp[N][N][N * 25];
int ans = 0;

void solve()
{
    cin >> n >> K;

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];

        while (a[i] % 2 == 0)
            freq2[i] ++ , a[i] /= 2;
        while (a[i] % 5 == 0)
            freq5[i] ++ , a[i] /= 5; 
    }
    
    for (int i = 0 ; i < n ; i ++)
        for (int j = 0 ; j < K ; j ++)
            for (int k = n * 25 ; k >= 0 ; k --)
                dp[i][j][k] = -1e6;    

    dp[0][0][0] = 0;

    for (int i = 0 ; i <= n ; i ++)
    {
        for (int j = 0 ; j <= min(i + 1 , K) ; j ++)
        {
            for (int k = 0 ; k <= K * 25 ; k ++)
            {
                dp[i + 1][j + 1][k + freq5[i]] = max(dp[i][j][k] + freq2[i] , dp[i + 1][j + 1][k + freq5[i]]);
                dp[i + 1][j][k] = max(dp[i + 1][j][k] , dp[i][j][k]);

                ans = max(ans , min(dp[i][j][k] , k));
            }
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