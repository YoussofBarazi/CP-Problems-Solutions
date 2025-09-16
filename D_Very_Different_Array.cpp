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
    int n , m;
    cin >> n >> m;
    
    vector <int> a(n) , c(m);
    for (int &i : a)
        cin >> i;

    for (int &i : c)
        cin >> i;

    sort(all(a));
    sort(all(c));

    int i = 0 , j = n - 1 , l = 0 , r = m - 1;
    ll ans = 0;
    while (i <= j)
    {
        int t = 1 , mx = abs(a[i] - c[l]);

        if (mx < abs(a[i] - c[r]))
        {
            mx = abs(a[i] - c[r]);
            t = 2;
        }
        if (mx < abs(a[j] - c[l]))
        {
            mx = abs(a[j] - c[l]);
            t = 3;
        }
        if (mx < abs(a[j] - c[r]))
        {
            mx = abs(a[j] - c[r]);
            t = 4;
        }

        ans += mx;

        if (t == 1)
            i ++ , l ++;
        else if (t == 2)
            i ++ , r --;
        else if (t == 3)
            j -- , l ++;
        else 
            j -- , r --;
    }

    cout << ans << endl;
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