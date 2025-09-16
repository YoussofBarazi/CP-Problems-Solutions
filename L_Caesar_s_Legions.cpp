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

const int N = 101 , M = 11;

int mem[N][N][M][M] , N1 , N2 , K1 , K2 , mod = 1e8;

int dp(int n1 , int n2 , int k1 , int k2)
{
    if (k1 > K1 || k2 > K2 || n1 > N1 || n2 > N2)
        return 0;

    if (n1 == N1 && n2 == N2)
        return 1;

    int &ret = mem[n1][n2][k1][k2];

    if (ret != -1)
        return ret;

    ret = (dp(n1 + 1 , n2 , k1 + 1 , 0) + dp(n1 , n2 + 1 , 0 , k2 + 1)) % mod;

    return ret;
}

void solve()
{
    cin >> N1 >> N2 >> K1 >> K2;

    memset(mem , -1 , sizeof mem);

    cout << dp(0 , 0 , 0 , 0);
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