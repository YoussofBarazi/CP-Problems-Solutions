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

void solve()
{
    int n , x;
    cin >> n >> x;

    vector <int> c(n) , h(n);

    int H = 0;

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> c[i] >> h[i];    
        H += h[i];
    }

    vector <ll> dp(H + 1 , 1e12);
        
    int ans = 0; dp[0] = 0;

    for (int i = 0 ; i < n ; i ++)
        for (int j = H ; j >= h[i] ; j --)
            if (dp[j - h[i]] + c[i] <= 1ll * i * x)
                dp[j] = min(dp[j] , dp[j - h[i]] + c[i]);

    for (int i = 0 ; i < n ; i ++)
        for (int j = 0 ; j <= H ; j ++)
            if (dp[j] <= 1ll * x * i)
                ans = max(ans , j);

    cout << ans << endl;
}

int main()
{
    // IO("name");
    //IOS;

    int t = 1;
    cin >> t;

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