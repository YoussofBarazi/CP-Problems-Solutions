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

const int N = 5000;

string s , t;
int dp[N][N];
bool vis[N][N];

int func(int i , int j)
{
    if (i == -1 && j == -1)
        return 0;

    if (i == -1 || j == -1)
        return max(i , j) + 1;

    int &ret = dp[i][j];
    
    if (vis[i][j])
        return ret;

    vis[i][j] = true;

    ret = min({func(i - 1 , j) + 1 , func(i , j - 1) + 1 , func(i - 1 , j - 1) + (s[i] != t[j])});

    return ret;
}

void solve()
{
    cin >> s >> t;

    cout << func(s.size() - 1 , t.size() - 1) << endl;
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