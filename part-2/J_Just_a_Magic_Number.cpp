#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define oo INT_MAX
#define OO LONG_MAX
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 100009;

int ans[N][101];

void get()
{
    for (int num = 0; num <= 1e5; num++)
    {
        int n = num;
        for (int i = 0; i <= 50; i++)
        {
            ans[num][i] = n;
            vi a;
            int q = 0, p = 0;

            while (n > 1)
            {
                a.pb(n % 10);
                n /= 10;
            }
            while (a.size() < 4)
            {
                a.pb(0);
            }

            sort(allrev(a));
            int t = 1;
            for (size_t i = 0; i < a.size(); i++)
            {
                p += a[i] * t;
                t *= 10;
            }
            for (size_t i = 0; i < a.size(); i++)
            {
                t /= 10;
                q += a[i] * t;
            }

            n = q - p;
        }
    }
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    cout << ans[n][min(k, 1ll * 50)] << endl;
}

int main()
{
    IOS;
    get();
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}