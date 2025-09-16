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
    ll a, b;
    cin >> a >> b;

    if (a > b)
        swap(a , b);

    a -- , b --;

    int ans = 0;
    
    for (ll x = 1 ; x <= a ; x ++)
    {
        ll yy = a * a - x * x;

        ll y = sqrt(yy);

        if (y * y == yy)
        {
            if (x * b % a == 0 && y * b % a == 0)
                ans ++;
        }
    }

    if (a != b)
        ans *= 2;

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

void IO(string name = "")
{

    cin.tie(0)->sync_with_stdio(0);
    if (name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}