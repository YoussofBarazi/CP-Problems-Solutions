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

int mod = 1e9 + 7;
int inv(int i)
{
    return i <= 1 ? i : mod - (long long)(mod / i) * inv(mod % i) % mod;
}

void solve()
{
    int n;
    cin >> n;

    ll mul = 1;
    vector <ll> a(n);
    for(auto &x : a)
    {
        cin >> x;

        mul *= x;
        mul %= mod;
    }

    ll ans = 0;

    for (auto x : a)
    {
        ll t = mul * inv(x) % mod;
        ans += (x - 1) * t;
        ans %= mod;
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