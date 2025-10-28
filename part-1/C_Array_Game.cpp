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

    vector <ll> a(n);

    for (auto &x : a)
        cin >> x;

    if (k > 2)
    {
        cout << "0" << endl;
        return ;
    }

    sort(all(a));

    ll ans = a[0];

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = i + 1 ; j < n ; j ++)
        {
            ans = min(ans , a[j] - a[i]);

            if (k == 2)
            {
                int ind = lower_bound(all(a) , a[j] - a[i]) - a.begin();

                ans = min(ans , a[ind] - (a[j] - a[i]));

                if (ind > 0)
                    ans = min(ans , (a[j] - a[i]) - a[ind - 1]);
            }
        }
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