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
    cin >> n;

    vector <int> a(n);
    map <int , vector <int>> ndxs;
    
    for (int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];

        ndxs[a[i]].push_back(i);
    }   

    ll ans = 1ll * n * (n + 1) / 2;

    for (int i = 0 ; i < n ; i ++)
    {
        if (ndxs[a[i]].front() < i)
            ans -= (n - i - 1);
        if (i < ndxs[a[i]].back())
            ans -= (i);
    }

    for (auto x : ndxs)
        if (x.S.size() != 1)
            ans -= x.S.size();

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