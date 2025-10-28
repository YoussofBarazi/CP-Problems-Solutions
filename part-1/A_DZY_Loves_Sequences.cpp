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

const int N = 100009;

int n;
int a[N];

void solve()
{
    cin >> n;

    for (int i = 1 ; i <= n ; i ++)
    {
        cin >> a[i];
    }

    vector <int> l(n + 2 , 1) , r(n + 2 , 1);

    a[0] = 0 , a[n + 1] = 1e9 + 7;
    l[0] = r[n + 1] = 0;

    for (int i = 2 ; i <= n ; i ++)
    {
        if (a[i] > a[i - 1])
            l[i] += l[i - 1];
    }

    for (int i = n - 1 ; i >= 1 ; i --)
    {
        if (a[i] < a[i + 1])
            r[i] += r[i + 1];
    }

    int ans = 0;

    for (int i = 1 ; i <= n ; i ++)
    {
        if (a[i - 1] + 1 < a[i + 1])
            ans = max(ans , l[i - 1] + r[i + 1] + 1);
    
        ans = max({ans , l[i - 1] + 1 , 1 + r[i + 1]});
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