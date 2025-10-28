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
    for (auto &x : a)
        cin >> x;

    map <pair<int , pair<int ,int>> , ll> freq;
    map <pair<int , pair<int ,int>> , ll> t1; 

    for (int i = 2 ; i < n ; i ++)
    {
        t1[{a[i - 2] , {a[i - 1] , a[i]}}] ++;

        freq[{0 , {a[i - 1] , a[i]}}] ++;
        freq[{a[i - 2] , {0 , a[i]}}] ++;
        freq[{a[i - 2] , {a[i - 1] , 0}}] ++;
    }
    
    ll ans = 0;

    for (auto x : freq)
    {
        ans += (x.S * (x.S - 1) / 2);
    }

    for (auto x : t1)
    {
        ans -= (x.S * (x.S - 1) / 2) * 3;
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