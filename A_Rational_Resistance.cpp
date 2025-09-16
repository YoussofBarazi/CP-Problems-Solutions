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

ll GCD(ll x, ll y , ll &cnt)
{
    if (y == 0)
        return x;

    cnt += x / y;

    return GCD(y, x % y , cnt);
}

void solve()
{
    ll a , b;
    cin >> a >> b;

    ll ans = 0;
    GCD(a , b , ans);

    cout << ans << endl;
}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}