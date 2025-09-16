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

int n , mod;

void solve()
{
    cin >> n >> mod;

    vector <int> a(n + 2 , 1);

    for (int i = 1 ; i <= n ; i ++)
    {
        cin >> a[i];
    }

    string s;
    cin >> s;

    int l = 1 , r = n;

    for (int i = 0 ; i < s.size() - 1 ; i ++)
    {
        if (s[i] == 'L')
            l ++;
        else 
            r --;
    }

    ll product = a[l] % mod;
    vector <int> ans; ans.pb(product);

    for (int i = n - 2 ; i >= 0 ; i --)
    {
        if (s[i] == 'L')
            product *= a[-- l] , product %= mod;
        else 
            product *= a[++ r] , product %= mod;
        
        ans.pb(product);
    }

    for (int i = n - 1 ; i >= 0 ; i --)
        cout << ans[i] << " ";
    cout << endl;
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