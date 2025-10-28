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

    vector <int> a(n + 3 , 0) , cnt(n + 3 , 0);

    ll all_sum = 0;

    for (int i = 1 ; i <= n ; i ++)
    {
        cin >> a[i];
        
        all_sum += a[i];
    }

    if (all_sum % 3)
    {
        cout << 0 << endl;
        return ;
    }

    ll s = 0 , ans = 0;

    for (int i = n ; i >= 1 ; i --)
    {
        s += a[i];

        cnt[i] = (s == (all_sum / 3)) + cnt[i + 1];
    }

    s = 0;

    for (int i = 1 ; i <= n ; i ++)
    {
        s += a[i];

        if (s == (all_sum / 3))
        {
            ans += cnt[i + 2];
        }
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