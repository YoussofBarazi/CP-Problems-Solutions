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

int mem[N][N];

int dp (int a1 , int a2)
{
    if ((a1 <= 0 || a2 <= 0) || (a1 == a2 && a1 == 1))
        return 0;

    int &ret = mem[a1][a2];

    if (ret != -1)
        return ret;

    if (a1 == 1)
        ret = dp(a1 + 1 , a2 - 2) + 1;
    else if (a2 == 1)
        ret = dp(a1 - 2 , a2 + 1) + 1;
    else 
        ret = max(dp(a1 + 1 , a2 - 2) , dp(a1 - 2 , a2 + 1)) + 1;

    return ret ;
}

void solve()
{
    int a , b;
    cin >> a >> b;

    memset(mem , -1 , sizeof mem);

    cout << dp(a , b) << endl;
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