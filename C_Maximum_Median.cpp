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

int a[N] , n , k;

bool ok(int m)
{
    ll cnt = 0;

    for (int i = n / 2 ; i < n ; i ++)
    {
        if (m > a[i])
        { 
            cnt += m - a[i] ;
        }
    }
    
    return cnt <= k;
}

void solve()
{
    cin >> n >> k;

    for (int i = 0 ; i < n ; i ++)
        cin >> a[i];

    sort(a , a + n);

    ll l = a[n / 2] , r = 2e9;

    while (l < r)
    {
        ll mid = (l + r + 1) / 2;

        if (ok(mid))
            l = mid;
        else 
            r = mid - 1;
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