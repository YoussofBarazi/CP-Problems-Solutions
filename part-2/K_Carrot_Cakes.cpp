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
    int n , t , k , d;
    cin >> n >> t >> k >> d;

    int one_oven_time = ((n + k - 1) / k) * t;

    int i;
    bool built = false;

    for (i = 0 ; i <= one_oven_time ; i ++)
    {
        if (n <= 0)
            break;

        built = (d <= i);

        if (built)
        {
            if (i - d > 0 && (i - d) % t == 0)
                n -= k;
        }
        
        if (i > 0 && i % t == 0)
            n -= k;
    }

    int two_ovens_time = i - 1;

    //cout << i - 1 << " " << one_oven_time << endl;
 
    if (one_oven_time <= two_ovens_time)
        cout << "NO" << endl;
    else 
        cout << "YES" << endl;
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