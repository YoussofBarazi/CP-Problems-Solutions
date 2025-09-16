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
    ll n , f , a , b;
    cin >> n >> f >> a >> b;

    vector <ll> m(n);
    
    for (ll &x : m)
        cin >> x;

    ll last = 0 , cost = 0;

    for (int i = 0 ; i < n ; i ++)
    {
        cost += min((m[i] - last) * a , b);
        last = m[i];
    }

    if (cost >= f)
        cout << "NO" << endl;
    else 
        cout << "YES" << endl;
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