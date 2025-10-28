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

const double pi = 3.141592653589793238;

void solve()
{
    double l , a;
    cin >> l >> a;

    double SIN = sin((a / 2) * pi / 180);

    double r = (l / 2) / SIN;

    double h = sqrt(r * r - (l * l) / 4);

    double ans = (a / 360) * (r * r * pi) - l * h / 2;

    cout << "area of the triangle : " << l * h / 2 << endl;
    cout << "area of the cyrcle : "  << pi * r * r / 2 << endl;
    cout << "area of X : " << (a * r * r * pi) / 360 << endl;;
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