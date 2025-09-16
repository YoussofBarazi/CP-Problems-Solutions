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

ll calc_dist (ll x , ll y)
{
    return sqrt(x * x + y * y);
}

void solve()
{
    ll r;
    cin >> r;

    ll x = 0 , y = r , ans = 0;

    for (x = 0 ; x <= r ; x ++)
    {
        while (calc_dist(x , y) >= r + 1)
            y --;

        ll t = y;

        while (0 < y && calc_dist(x , y) == r)
            ans ++ , y --;

        swap(t , y);
    }

    cout << ans * 4 << endl;
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