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
    ll n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    int l = 0, r = n - 1;
    int ans = 0;
    ll t = 0;

    while (l < r && k > 0)
    {
        int mn = min(a[l], a[r]);
        
        if (mn * 2 - 1 <= k)
        {
            a[l] -= mn;
            k -= mn;

            if (a[l] == 0)
                ans++, l++;
        }
        else
            break;

        if (mn <= k)
        {
            a[r] -= mn;
            k -= mn;
            if (a[r] == 0)
                ans++, r--;
        }
        else
            break;
    }

    if (l == r && a[l] <= k)
        ans ++;

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

void IO(string name = "")
{

    cin.tie(0)->sync_with_stdio(0);
    if (name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}