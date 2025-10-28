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

ll n;

ll logb(ll a, ll b)
{
    return log2(a) / log2(b);
}

ll sum(ll base, ll size)
{
    ll s = 0;
    ll t = 1;
    for (int i = 0; i <= size; i++)
    {
        s += t;
        t *= base;
    }

    return s;
}

bool check(int size)
{
    ll l = 2, r = 1e9, base;

    while (l <= r)
    {
        base = (r + l) / 2;

        if (logb(1e18, base) < size)
        {
            r = base - 1;
            continue;
        }

        ll s = sum(base, size);

        if (s == n)
            return true;
        else if (s > n)
            r = base - 1;
        else
            l = base + 1;
    }

    return false;
}

void solve(int test)
{
    cin >> n;

    ll size = log2(n);

    for (int i = 2; i <= size; i++)
    {
        if (check(i))
        {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main()
{
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve(t);
    }

    return 0;
}