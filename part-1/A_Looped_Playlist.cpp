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

const int N = 200009;

void solve()
{
    ll n, p;
    cin >> n >> p;

    vector<ll> a(n);
    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 0 ; i < n - 1 ; i ++)
    {
        a.pb(a[i]);
    }

    ll ans = (p / sum) * n;

    p %= sum;

    int j = 0;
    sum = 0;
    n *= 2;
    n --;

    int ind = -1 , mn = 1e9;
    for (int i = 0 ; i < n ; i ++)
    {
        while (j < n && sum < p)
        {
            sum += a[j];
            j ++;
        }

        if (sum >= p && j - i < mn)
        {
            mn = j - i;
            ind = i + 1;
        }

        sum -= a[i];
    }

    cout << ind << " " << mn + ans << endl;
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