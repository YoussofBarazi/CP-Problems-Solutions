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
    int a[3];

    for (int i = 0 ; i < 3 ; i ++)
        cin >> a[i];

    sort(a , a + 3);

    int mn = min(a[1] - a[0] - 1 , a[2] - a[1] - 1);
    int mx = max(a[1] - a[0] - 1 , a[2] - a[1] - 1);
    
    if (mn == 0)
        mn = mx;
        
    mn = min(mn , 2);

    cout << mn << endl << mx << endl;
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