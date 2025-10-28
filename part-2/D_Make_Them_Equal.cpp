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

const int N = 1001;

int d[N] , b[N] , c[N] , mem[N][N * 12];

void precalc()
{
    for (int i = 0 ; i < N ; i ++)
        d[i] = 1e9;

    d[1] = 0;
    for (int i = 1; i < N; ++i) 
    {
        for (int x = 1; x <= i; ++x) 
        {
            int j = i + i / x;
            if (j < N) d[j] = min(d[j], d[i] + 1);
        }
    }
}

int n , k;

int dp (int i , int w)
{
    if (i == n)
        return 0;

    int &ret = mem[i][w];

    if (ret != -1)
        return ret;

    ret = dp(i + 1 , w);

    if (w + d[b[i]] <= k)
        ret = max(ret , dp(i + 1 , w + d[b[i]]) + c[i]);

    return ret;
}

void solve()
{
    cin >> n >> k;

    k = min(k , n * 12);

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> b[i];
    }
    for (int i = 0 ; i < n ; i ++)
    {
        cin >> c[i];
    }

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = 0 ; j <= k ; j ++)
        {
            mem[i][j] = -1;
        }
    }

    cout << dp(0 , 0) << endl;
}


int main()
{
    // IO("name");
    IOS;

    precalc();

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