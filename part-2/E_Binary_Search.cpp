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
    int n , x;
    cin >> n >> x;

    vector <int> a(n + 1);
    int ndx = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> a[i];
        ndx = (a[i] == x)? i : ndx;
    }

    int l = 1 , r = n + 1;
    while (r - l > 1)
    {
        int m = (l + r) / 2;

        if (a[m] <= x)
            l = m;
        else  
            r = m;
    }

    cout << 1 << endl << ndx << " " << l << endl;
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