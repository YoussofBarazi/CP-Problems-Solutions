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
    int n;
    cin >> n;

    vector <int> a(n);
    vector <string> s(n);

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> a[i] >> s[i];
    }

    vector <int> dp(8 , 1e6);
    dp[0] = 0;
    
    for (int sub = 0 ; sub < 8 ; sub ++)
    {
        for (int i = 0 ; i < n ; i ++)
        {
            int sub2 = 0;

            for (auto c : s[i])
            {
                int t = c - 'A';
                sub2 |= (1 << t);
            }

            dp[sub | sub2] = min(dp[sub | sub2] , dp[sub] + a[i]);
        }
    }

    if (dp[7] == 1e6)
        dp[7] = -1;

    cout << dp[7] << endl;
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