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
    vector <int> zero;

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];
    }

    int s = 0;
    while (s < n && a[s] == 0)
        s ++;

    for (int i = s ; i < n ; i ++)
    {
        if (!a[i])
            zero.push_back(i);
    }

    int ans = 0;

    for (int i = n - 1 ; i >= 0 ; i --)
    {
        if (a[i] == 1 && zero.size() == 0)
            break;

        if (a[i] == 1)
        {
            int x = zero.back();
            zero.pop_back();
            a[x] = 1;
            ans ++;
        }
        else
        {
            zero.pop_back();
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