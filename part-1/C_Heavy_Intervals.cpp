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
    int n;
    cin >> n ;

    set <ll> r;
    vector <ll> l(n) , c(n);
    
    for (auto &x : l)
        cin >> x;
    for (int i = 0 ; i < n ; i ++)
    {
        int x;
        cin >> x;

        r.insert(x);
    }
    for (auto &x : c)
        cin >> x;

    sort(allr(l)) , sort(allr(c));

    ll ans = 0;
    vector <pair<ll , pll>> interval;
    
    for (int i = 0 ; i < n ; i ++)
    {
        ll L = l[i];
        auto x = r.lower_bound(l[i]);
        ll R = *x;

        interval.push_back({R - L , {L , R}});

        r.erase(x);
    }

    sort(all(interval));

    for (int i = 0 ; i < n ; i ++)
        ans += interval[i].F * c[i];

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