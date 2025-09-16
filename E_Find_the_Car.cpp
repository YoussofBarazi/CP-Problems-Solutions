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
    int n , k , q;
    cin >> n >> k >> q;

    vector <ll> a(k + 1 , 0) , b(k + 1 , 0);

    for (int i = 1 ; i <= k ; i++)
        cin >> a[i];

    for (int i = 1 ; i <= k ; i ++)
    {
        cin >> b[i];
    }

    for (int i = 0 ; i < q ; i ++)
    {
        int d;
        cin >> d;

        int l = lower_bound(all(a) , d) - a.begin() , r = l;

        if (a[l] > d)
            l --;
        else if (d == a[l])
        {
            cout << b[l] << " ";
            continue;
        }

        ll dist = a[r] - a[l];
        ll time = b[r] - b[l];

        ll ans = b[l] + (d - a[l]) * time / dist;

        cout << ans << " ";
    }
    cout << endl;
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