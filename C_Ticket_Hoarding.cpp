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
    int n , m , k;
    cin >> n >> m >> k;

    vector <int> a(n) ; vector <pii> b , c;

    for (auto &x : a)
    {
        cin >> x;

        b.pb({x , 0});
    }

    sort(all(b));

    int cnt = (k + m - 1) / m;
    ll ans = 0;
    
    for (int i = 0 ; i < cnt ; i ++)
    {
        c.pb({b[i].S , b[i].F});
    }

    sort(all(c));

    for (ll i = 0 ; i < cnt ; i ++)
    {
        if (cnt == i + 1 && k % m > 0)
            ans += (c[i].S + i * m) * 1ll * (k % m);
        else 
            ans += (c[i].S + i * m) * 1ll * m;
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