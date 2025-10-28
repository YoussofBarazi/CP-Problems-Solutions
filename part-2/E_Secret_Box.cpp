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
    ll x , y , z , k;
    cin >> x >> y >> z >> k;

    ll tx , ty , tz;
    ll ans = 0;

    for (ll i = 1 ; i <= x ; i ++)
    {
        for (ll j = 1 ; j <= y ; j ++)
        {
            if (k % (i * j) == 0 && k / (i * j) <= z)
            {
                tx = i , ty = j , tz = k / (i * j);

                ll res = (x - tx + 1) * (y - ty + 1) * (z - tz + 1);

                if (ans < res)
                    ans = res;
            }
        }
    }

    cout << ans << endl;
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