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
    string s1 , s2;
    cin >> s1 >> s2;

    vector <vector<int>> dp(s1.size() + 1 , vector <int> (s2.size() + 1 , 0));

    for (int i = 1 ; i <= s1.size() ; i ++)
    {
        for (int j = 1 ; j <= s2.size() ; j ++)
        {
            dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);

            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = max(dp[i][j] , dp[i - 1][j - 1] + 1);
        }
    }

    int i = s1.size() , j = s2.size();
    string ans;

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
            ans.push_back(s1[i - 1]) , i -- , j --;
        else if (dp[i - 1][j] > dp[i][j - 1])
            i --;
        else  
            j --;
    }

    reverse(all(ans));

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