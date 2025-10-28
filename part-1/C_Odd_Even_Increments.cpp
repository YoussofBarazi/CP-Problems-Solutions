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

    vector <int> a(n) ;

    for (auto &x : a)
        cin >> x;

    int parity_cnt1 = 0 , parity_cnt2 = 0;
    for (int i = 0 ; i < n ; i ++)
    {
        if (i % 2)
            parity_cnt2 += a[i] % 2;  
        else 
            parity_cnt1 += a[i] % 2;
    }

    if ((parity_cnt1 == (n + 1) / 2 || parity_cnt1 == 0) && (parity_cnt2 == n / 2 || parity_cnt2 == 0))
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
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