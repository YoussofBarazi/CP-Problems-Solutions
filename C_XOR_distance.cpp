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
    ll a , b , r;
    cin >> a >> b >> r;

    if (a < b)
        swap(a , b);

    ll x = 0 , ans = a - b , i;

    for (i = 62 ; i >= 0 ; i --)
    {
        if ((a & (1ll << i)) != (b & (1ll << i)))
        {
            i--;
            break;
        }
    }

    for (; i >= 0 ; i --)
    {
        if ((a & (1ll << i)) != (b & (1ll << i)) && ((x | (1ll << i)) <= r))
        {
            x |= (1ll << i);

            if (abs((a ^ x) - (b ^ x)) < ans)
                ans = abs((a ^ x) - (b ^ x));
            else 
                x ^= (1ll << i);
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