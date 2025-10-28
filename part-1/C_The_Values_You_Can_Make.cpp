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

const int N = 501;

bool dp[N][N][N];

void solve()
{
    int n , k;
    cin >> n >> k;

    vector <int> a(n);
    
    for (auto &x : a)
        cin >> x;

    sort(all(a));

    dp[0][0][0] = true;

    for (int i = 1 ; i <= n ; i ++)
    {
        for (int x = k ; x >= 0 ; x --)
        {
            for (int y = k ; y >= 0 ; y --)
            {
                dp[i][x][y] = dp[i - 1][x][y];

                if (y >= a[i - 1])
                    dp[i][x][y] |= dp[i - 1][x][y - a[i - 1]];

                if (x >= a[i - 1])
                    dp[i][x][y] |= dp[i - 1][x - a[i - 1]][y];
            }
        }
    }

    vector <int> ans;

    for (int i = 0 ; i <= k ; i ++)
    {
        if (dp[n][i][k - i])
            ans.push_back(i);
    }

    cout << ans.size() << endl;

    for (auto &x : ans)
        cout << x << " ";
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