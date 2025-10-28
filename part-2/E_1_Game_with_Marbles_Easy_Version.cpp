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

const int N = 2e5;

int n;
int a[N] , b[N];

void solve()
{
    cin >> n;

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];
    }

    vector <pii> s;

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> b[i];

        s.pb({a[i] + b[i] , i});
    }

    sort(allr(s));

    ll ans = 0;

    for (int i = 0 ; i < n ; i ++)
    {
        if (i % 2 == 0)
            ans += a[s[i].S] - 1;
        else 
            ans -= b[s[i].S] - 1;
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