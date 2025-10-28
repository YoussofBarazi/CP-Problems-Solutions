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

    for (auto &x : a)
        cin >> x;

    vector <int> b = {a[0]}, c;
    int ans = 0;

    for (int i = 1 ; i < n ; i ++)
    {
        int x = b.back() , y = (c.size())? c.back() : 0 ;

        if (a[i] <= min(x , y))
        {
            if (x <= y)
                b.push_back(a[i]);
            else 
                c.push_back(a[i]);
        }
        else if (a[i] <= max(x , y))
        {
            if (x >= y)
                b.push_back(a[i]);
            else 
                c.push_back(a[i]);
        }        
        else 
        {
            if (x <= y)
                b.push_back(a[i]);
            else
                c.push_back(a[i]);
        }
    }

    for (int i = 1 ; i < b.size() ; i ++)
        ans += b[i - 1] < b[i];

    for (int i = 1 ; i < c.size() ; i ++)
        ans += c[i - 1] < c[i];

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