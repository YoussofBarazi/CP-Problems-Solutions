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

ll arithmetic_progression(ll first, ll last, ll size)
{
    return ((first + last) * size) / 2;
}

void solve()
{
    int n;
    cin >> n;

    vector <ll> ans;

    for (ll i = 1 ; i * i <= n ; i ++)
    {
        if (n % i == 0)
        {
            ans.pb(arithmetic_progression(1 , 1 + ((n - 1) / i) * i , n / i));

            if (i * i != n)
                ans.pb(arithmetic_progression(1 , 1 + ((n - 1) / (n / i)) * (n / i) , i));
        }
    }

    sort(all(ans));

    for (auto x : ans)
        cout << x << " ";
    cout << endl;
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