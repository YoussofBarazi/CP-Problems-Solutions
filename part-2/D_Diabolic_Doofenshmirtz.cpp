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
    ll t = 1;
    ll x = 0 , last;

    bool ok = true;

    while(ok)
    {
        cout << "? " << t << endl;
        cout.flush();

        ll tx;
        cin >> tx;

        if (tx > x)
        {
            x = tx;
        }
        else 
        {
            last = tx;
            break;
        }

        t *= 2;
    }

    ll y = t - x - last;

    cout << "! " << x + y << endl;
    cout.flush();
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;

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