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
    int b[4] , a[4];
    
    for (int i = 0 ; i < 4 ; i ++)
    {
        cin >> b[i] >> a[i];
    }

    int ans[4] = {} , cnt = 0;

    for (int i = 3 ; i >= 0 ; i --)
    {
        cnt += a[i] - b[i];
        ans[i] = cnt;
    }

    for (int i = 1 ; i < 4 ; i ++)
    {
        cout << ans[i] << endl;
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