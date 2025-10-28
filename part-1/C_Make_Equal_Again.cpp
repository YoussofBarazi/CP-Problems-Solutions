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

    vector <int> a(n);
    for(auto &x : a)
        cin >> x;

    int i = 1 , j = n - 1;

    while (i < n && a[i] == a[i - 1])
        i ++;

    while (j > 1 && a[j] == a[j - 1])
        j --;

    int ans = min(n - i , j);

    i = 0 , j = n - 1;

    while (i < n && a[i] == a.back())
        i ++;
    while (j >= 0 && a[j] == a.front())
        j --;

    if (i <= j)
        ans = min(ans , j - i + 1);

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