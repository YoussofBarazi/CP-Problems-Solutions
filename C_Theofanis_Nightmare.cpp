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

int n;
int a[N];

void solve()
{
    cin >> n;

    for (int i = 0 ; i < n ; i ++)
        cin >> a[i];
        
    vector <ll> ans;

    ll sum = 0 , cur = 0;

    for (int i = n - 1 ; i >= 0 ; i --)
    {
        sum += a[i];
        cur += a[i];

        if (sum >= 0)
            ans.pb(cur) , cur = 0;
    }

    if (cur != 0)
        ans.pb(cur);

    reverse(all(ans));
    sum = 0;

    for (int i = 0 ; i < ans.size() ; i ++)
        sum += (i + 1) * ans[i];

    cout << sum << endl;
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