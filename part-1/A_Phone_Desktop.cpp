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
    int x , y;
    cin >> x >> y;

    int cnt = 0;

    while (x > 0 || y > 0)
    {
        if (y > 0)
        {
            if (y >= 2)
            {
                y -= 2;
                x -= 7;
                cnt ++;
            }
            else 
            {
                y -= 1;
                x -= 11;
                cnt ++;
            }
        }
        else 
            cnt ++ , x -= 15;
    }

    cout << cnt << endl;
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