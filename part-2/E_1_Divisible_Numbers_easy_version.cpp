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

const int N = 200009;

vector<int> fact(1e5 + 1, 0);

void get()
{
    for (int i = 2; i <= 1e5; i++)
    {
        if (fact[i] == 0)
            for (int j = i; j <= 1e5; j += i)
                fact[j] = i;
    }
}

void factorize(int x, map<int, int> &m)
{
    while (x > 1)
    {
        int div = fact[x];
        while (x % div == 0)
        {
            x /= div;
            m[div]++;
        }
    }
}

long long POW(long long x, long long y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;

    long long ans = POW(x, y / 2);

    if (y & 1)
        return ans * ans * x;
    return ans * ans;
}

void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    map<int, int> abFact;

    factorize(a, abFact);
    factorize(b, abFact);

    for (ll x = a + 1; x <= c; x++)
    {
        map<int, int> f;
        factorize(x, f);

        ll mn = 1;
        for (auto i : abFact)
        {
            if (i.S > f[i.F])
                mn *= POW(i.F, i.S - f[i.F]);
        }

        for (ll y = mn; y <= d; y += mn)
        {
            if (y > b && (x * y) % (a * b) == 0)
            {
                cout << x << " " << y << endl;
                return;
            }
        }
    }

    cout << -1 << " " << -1 << endl;
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