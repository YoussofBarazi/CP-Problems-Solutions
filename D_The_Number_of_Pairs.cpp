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

const int N = 20000009;

int gpf[N];

void get()
{
    gpf[1] = gpf[0] = 1;
    for (int i = 2; i < N; i++)
        if (gpf[i] == 0)
            for (int j = i; j < N; j += i)
                gpf[j] = i;
}

int c, d, x;

void calc(int g, vector<int> &v)
{
    int k = x / g + d;

    if (k % c)
        return;

    k /= c;

    int cnt = 0;

    while (k > 1)
    {
        int p = gpf[k];
        cnt++;
        while (k % p == 0)
            k /= p;
    }

    v.pb(cnt);
}

void solve()
{
    cin >> c >> d >> x;

    vector<int> v;
    for (int g = 1; g * g <= x; g++)
    {
        if (x % g == 0)
        {
            calc(g, v);
            if (g * g != x)
                calc(x / g, v);
        }
    }

    ll ans = 0;
    for (int x : v)
        ans += (1 << x);

    cout << ans << endl;
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