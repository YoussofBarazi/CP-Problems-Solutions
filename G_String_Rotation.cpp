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
    int n , x;
    cin >> n >> x;

    string s , t;
    cin >> s >> t;

    x %= n;

    string tmp = string(n , '.');

    for (int i = 0 ; i < n ; i ++)
        tmp[(i + x) % n] = s[i];

    s = tmp;

    int cnt = 0;
    for (int i = 0 ; i < n ; i ++)
        cnt += s[i] != t[i];

    cout << cnt << endl;
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