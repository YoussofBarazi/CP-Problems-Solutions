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

const int N = 1009;

int n , k , mod = 1e9 + 7;
int DP[N][N][50];

int dp(int a , int def , int cnt)
{
    if (cnt == k)
    {
        return 1;
    }
    
    if (a + def > n)
        return 0; 
    
    int &ret = DP[a][def][cnt];

    if (~ret)
        return ret;

    ret = (dp(a , def + 1 , cnt) + dp(a + 1 , def , cnt) + dp(a + 1 , def + 1 , cnt + 1)) % mod;   

    return ret;
}

void solve()
{
    cin >> n >> k;

    for (int i = 0 ; i <= n ; i ++)
        for (int j = 0 ; j <= n ; j ++)
            for (int w = 0 ; w < k ; w ++)
                DP[i][j][w] = -1;

    if (k > 50)
        cout << 0 << endl;
    else 
        cout << dp(1 , 0 , 0) << endl;
}

int main()
{
    // IO("name");
    IOS;

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