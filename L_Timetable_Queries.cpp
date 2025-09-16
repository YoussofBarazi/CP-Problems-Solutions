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
    int n , q;
    cin >> n >> q;

    map <int , vector<int>> m;

    for (int i = 1 ; i <= n ; i ++)
    {
        int x;
        cin >> x;

        m[x].push_back(i);
    }

    for (int i = 0 ; i < q ; i ++)
    {
        int x , y;
        cin >> x >> y;

        if (y > m[x].size())
        {
            cout << -1 << endl;
        }
        else 
        {
            cout << m[x][y - 1] << endl;
        }
    }
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