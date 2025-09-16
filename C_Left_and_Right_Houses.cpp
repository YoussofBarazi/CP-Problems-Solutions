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

    string s;
    cin >> s;

    vector <int> sum(n + 1 , 0);

    for (int i = 0 ; i < n ; i ++)
    {
        sum[i + 1] = s[i] == '1';
        
        sum[i + 1] += sum[i];
    }

    vector <int> ans ;

    for (int i = 0 ; i <= n ; i ++)
    {
        int x = i , left = x - sum[i] , right = sum.back() - sum[i];

        //  1 0 1 0 1 1
    //    0 1 2 3 4 5 6 7

        if ((i == 0 || left >= (x + 1) / 2) && (right >= (n - x + 1) / 2))
        {
            ans.pb(x);
        }
    }

    int t = n;
    int res = -1;

    // min(|n / 2.0 - i|)

    for (int x : ans)
    {
        int tt = abs((n / 2.0) - x);

        if (t - tt > 0)
        {
            res = x;
            t = tt;
        }
    }

    cout << res << endl;
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