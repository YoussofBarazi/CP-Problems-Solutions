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

ll n , DP[N][3] , cnt0 , cnt1 , cnt2 , mod = 1e9 + 7;

ll dp(int i , int s)
{
    s %= 3;

    if (i == n)
        return (s == 0);

    ll &ret = DP[i][s];

    if (~ret)
        return ret;

    ret = (dp(i + 1 , s) * cnt0 % mod + dp(i + 1 , s + 1) * cnt1 % mod + dp(i + 1 , s + 2) * cnt2 % mod) % mod; 

    return ret;
}

void solve()
{
    int l , r;
    cin >> n >> l >> r;

    cnt0 = r / 3 - (l - 1) / 3;
    cnt1 = (r + 2) / 3 - (l + 1) / 3;
    cnt2 = (r + 1) / 3 - l / 3;
    
    memset(DP , -1 , sizeof DP);

    cout << dp(0 , 0) << endl;
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