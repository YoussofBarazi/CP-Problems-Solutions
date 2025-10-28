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
    int q , k;
    cin >> q >> k;

    vector <ll> dp(k + 1 , 0);
    dp[0] = 1;
    ll mod = 998244353;

    while (q --)
    {
        char t ; int x ;
        cin >> t >> x;

        if (t == '+')
        {
            for (int i = k ; i >= x ; i --)
            {
                dp[i] = (dp[i] + dp[i - x]) % mod;
            }
        }
        else 
        {
            for (int i = x ; i <= k ; i ++)
            {
                dp[i] = (dp[i] + mod - dp[i - x]) % mod;
            }
        }

        cout << dp[k] << endl;
    }
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