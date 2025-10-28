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

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 200009;

ll calc(int ndx , vector <int> &a , int n)
{
    int g = 0;
    ll ans = 0;

    for (int i = 1 ; i <=  n; i ++)
    {
        if (ndx == i)
            continue;

        g = gcd(g , a[i]);
        ans += g;
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    vector <int> a(n + 2 , 0) , pref_gcd(n + 2 , 0) , suff_gcd(n + 2 , 0);
    int ndx = 0;

    for (int i = 1 ; i <= n ; i ++)
    {    
        cin >> a[i];
        pref_gcd[i] = gcd(pref_gcd[i - 1] , a[i]);
    }

    // for (int i = n ; i >= 1 ; i --)
    //     suff_gcd[i] = gcd(suff_gcd[i + 1] , a[i]);

    for (int i = n ; i >= 1 ; i --)
    {
        if (gcd(pref_gcd[i - 1] , a[i + 1]) > pref_gcd[i])
        {
            ndx = i;
            break;
        }
    }

    if (ndx == 0)
        ndx = n;

    ll ans = calc(ndx , a , n);
    
    ndx = 0;

    for (int i = 2 ; i <= n ; i ++)
    {
        if (pref_gcd[i] < gcd(pref_gcd[i - 1] , a[i + 1]))
        {
            ndx = i;
            break;
        }
    }

    if (ndx == 0)
        ndx = n;

    ans = max(ans , calc(ndx , a , n));

    cout << ans << endl;
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