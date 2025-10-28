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

const int N = 100009;

void solve()
{
    ll a , b , n;
    cin >> a >> b >> n;

    ll x = 1;

    set <int> s;

    while (true)
    {
        ll y = a * x * x + b * x;

        if (y > n)
        {
            break;
        }

        s.insert(y);
        x++;
    }

    vector <int> points(10 , 0);
    
    for (auto x : s)
    {
        int t = x , mx = 0;

        vector <int> freq(10 , 0);

        while (t > 0)
        {
            freq[t % 10] ++;
            mx = max(freq[t % 10] , mx);
            t /= 10;
        }

        for (int i = 0 ; i < 10 ; i ++)
        {
            if (freq[i] == mx)
            {
                points[i] ++;
            }
        }
    }

    int ans = -1 , mx = 0;

    for (int i = 0 ; i < 10 ; i ++)
    {
        if (mx < points[i])
        {
            ans = i , mx = points[i];
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