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

const int N = 3009;

int n;
double p[N];
double mem[N][N];
bool vis[N][N];

double dp(int i , int h)
{
    if (i == n)
    {
        return h > n / 2;
    }

    double &ret = mem[i][h];

    if (vis[i][h])
        return ret;

    vis[i][h] = true;

    return ret = dp(i + 1 , h + 1) * p[i] + dp(i + 1 , h) * (1 - p[i]);
}

void solve()
{
    cin >> n;

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> p[i];
    }    

    cout << fixed << setprecision(10);
    cout << dp(0 , 0);
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