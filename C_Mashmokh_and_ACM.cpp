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

const int N = 2002;

ll n , k , mod = 1e9 + 7;
ll mem[N][N];

ll dp(int i , int s)
{
    if (s == k)
        return 1;

    ll &ret = mem[i][s];

    if (ret != -1)
        return ret;

    ret = 0;

    for (int j = i ; j <= n ; j += i)
    {
        ret += dp(j , s + 1);
        ret %= mod;
    }

    return ret;
}

void solve()
{
    cin >> n >> k;

    memset(mem , -1 , sizeof mem);

    cout << dp(1 , 0) << endl;
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