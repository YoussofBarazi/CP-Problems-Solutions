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

    vector <ll> a(n) , t;
    ll mx = -1e2 , mn = 1e2 , ndx1 , ndx2;

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];

        if (mx < a[i])
            ndx1 = i , mx = a[i];
        if (mn > a[i])
            ndx2 = i , mn = a[i];
    }

    t = a;

    if (is_sorted(all(a)))
    {
        cout << 0 << endl;
        return ;
    }

    vector <pii> ans1 , ans2;

    if (mn < 0)
    {
        while (mn + mx > 0)
        {
            ans1.pb({ndx2 , ndx2});
            mn *= 2;
            a[ndx2] = mn;
        }

        for (int i = n - 1 ; i >= 0 ; i --)
        {
            if (a[i] > 0)
            {
                ans1.pb({i , ndx2});
                a[i] += a[ndx2];
            }

            if (i + 1 < n && a[i] > a[i + 1])
            {
                ans1.pb({i , i + 1});
                a[i] += a[i + 1];
            }
        }
    }
    
    a = t;

    if (mx > 0)
    {
        while (mn + mx < 0)
        {
            ans2.pb({ndx1 , ndx1});
            mx *= 2;
            a[ndx1] = mx;
        }

        for (int i = 0 ; i < n ; i ++)
        {
            if (a[i] < 0)
            {
                ans2.pb({i , ndx1});
                a[i] += a[ndx1];
            }
            
            if (i > 0 && a[i - 1] > a[i])
            {
                ans2.pb({i , i - 1});
                a[i] += a[i - 1];    
            }
        }
    }

    if (ans1.size() == 0 || (ans1.size() > ans2.size() && ans2.size()))
        swap(ans1 , ans2);

    cout << ans1.size() << endl;
    for (auto x : ans1)
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