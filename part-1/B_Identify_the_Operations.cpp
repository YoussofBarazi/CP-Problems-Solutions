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
    int n , k;
    cin >> n >> k;

    vector <int> ndx(n + 1);
    vector <int> a(n) , b(k);
    vector <bool> allowed(n + 1 , true);

    for (int i = 0 ; i < n ; i ++)
    {    
        cin >> a[i];
        ndx[a[i]] = i;
    }

    for (auto &x : b)
    {
        cin >> x;

        allowed[ndx[x]] = false;
    }

    ll ans = 1 , mod = 998244353;

    for (auto x : b)
    {
        int cnt = 0;

        if (ndx[x] + 1 < n)
            cnt += allowed[ndx[x] + 1];
        if (ndx[x] - 1 >= 0)
            cnt += allowed[ndx[x] - 1];

        ans *= cnt;
        ans %= mod;
        allowed[ndx[x]] = true;
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