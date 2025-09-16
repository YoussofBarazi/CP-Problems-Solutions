#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
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

const int N = 4000009;

void solve()
{
    ll n;
    cin >> n;

    ll p = 0;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            p = i;
            break;
        }

    if (!p)
    {
        cout << 1 << endl
             << 0 << endl;
        return;
    }

    ll q = 0;
    n /= p;

    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            q = i;
            break;
        }
    }

    if (!q)
    {
        cout << 2 << endl;
        return;
    }

    cout << 1 << endl
         << p * q << endl;
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