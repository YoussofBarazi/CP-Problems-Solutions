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
    int n;
    cin >> n;

    vector <ll> a(n);
    ll mx = -1e2 , mn = 1e2 , ndx1 , ndx2;

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];

        if (mx < a[i])
            ndx1 = i , mx = a[i];
        if (mn > a[i])
            ndx2 = i , mn = a[i];
    }

    if (is_sorted(all(a)))
    {
        cout << 0 << endl;
        return ;
    }

    vector <pii> ans;

    if (mx <= 0)
    {
        for (int i = n - 2 ; i >= 0 ; i --)
        {
            ans.pb({i , i + 1});
        }
    }
    else 
    {
        while (abs(mn) > mx)
        {
            ans.pb({ndx1 , ndx1});
            mx *= 2;
            a[ndx1] = mx;
        }

        for (int i = 0 ; i < n ; i ++)
        {
            if (a[i] < 0)
            {
                ans.pb({i , ndx1});
                a[i] += a[ndx1];
            }
            
            if (i > 0)
                ans.pb({i , i - 1});
        }
    }

    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x.F + 1 << " " << x.S + 1 << endl;
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