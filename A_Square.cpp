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
    int a , b , minx = 1e9 , miny = 1e9 , maxx = -1e9 , maxy = -1e9;

    for (int i = 0 ; i < 4 ; i ++)
    {
        cin >> a >> b;

        minx = min(a , minx);
        miny = min(b , miny);
        maxx = max(a , maxx);
        maxy = max(b , maxy);
    }

    cout << (maxx - minx) * (maxy - miny) << endl;

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