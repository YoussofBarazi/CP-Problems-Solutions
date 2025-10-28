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

ll n;

bool ok(ll mid)
{
    ll cnt = 0;
    for (int i = 1 ; i <= min(n , mid) ; i ++)
    {
        cnt += min(n , mid / i);
    }

    return cnt >= n * n / 2 + 1;
}

void solve()
{
    cin >> n;

    ll l = 1 , r = n * n;
    while (l < r)
    {
        ll mid = (l + r) / 2;

        if (ok(mid))
            r = mid;
        else 
            l = mid + 1;
    }

    cout << l << endl;
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