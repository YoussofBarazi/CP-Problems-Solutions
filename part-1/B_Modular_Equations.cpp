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
    int a , b;
    cin >> a >> b;

    if (a == b)
    {
        cout << "infinity" << endl;
        return ;
    }
    else if (a < b)
    {
        cout << 0 << endl;
        return ;
    }

    int ans = 0;

    for (int i = 1 ; i * i <= a - b ; i ++)
    {
        if ((a - b) % i == 0)
        {
            if (a % i == b)
                ans ++;
            if (a % ((a - b) / i) == b && i * i != (a - b))
                ans ++;
        }
    }

    cout << ans << endl;
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