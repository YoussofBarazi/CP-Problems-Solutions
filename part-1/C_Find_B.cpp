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

    vector <ll> sum(n + 1 , 0) , ones(n + 1 , 0);

    for (int i = 1 ; i <= n ; i ++)
    {
        int x;
        cin >> x;

        ones[i] = ones[i - 1] + bool(x == 1);
        sum[i] = sum[i - 1] + x;
    }

    for (int i = 0 ; i < q ; i ++)
    {
        int l , r;
        cin >> l >> r;

        ll s = sum[r] - sum[l - 1] , len = r - l + 1 , one = ones[r] - ones[l - 1];

        if (len == 1 || (((s / len) == 1) && ((s % len) < one)))
            cout << "NO" << endl;
        else 
            cout << "YES" << endl;
    }
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