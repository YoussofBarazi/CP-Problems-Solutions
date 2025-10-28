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
    int a;
    cin >> a;

    int b = 0;

    for (int i = 24 ; i >= 0 ; i --)
    {
        if (a & (1 << i))
            continue;
        
        if (b | (1 << i) < a)
            b |= (1 << i);
    } 

    if (b == 0)
        b = 1;

    int ans = gcd((a ^ b) , (a & b));

    ans = max(ans , gcd(a ^ 1 , a & 1));

    for (int i = sqrt(a) ; i >= 2 ; i --)
    {
        if (a % i == 0)
        {
            b = i;
            ans = max(ans , gcd((a ^ b) , (a & b)));
            b = a / i;
            ans = max(ans , gcd((a ^ b) , (a & b)));
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