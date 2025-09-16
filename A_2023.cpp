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
    int n , k;
    cin >> n >> k;

    ll mul = 1;
    for (int i = 0 ; i < n ; i ++)
    {
        int x;
        cin >> x;

        mul *= x;
    }

    for (int i = 1 ; i <= 2023 ; i ++)
    {
        if (mul * i == 2023)
        {
            cout << "YES" << endl;
            cout << i << " " ;
            for (int i = 0 ; i < k - 1 ; i ++)
                cout << 1 << " " ;
            cout << endl;
            return;
        }
    }

    cout << "NO" << endl;
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