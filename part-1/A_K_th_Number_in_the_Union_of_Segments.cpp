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

int l[N] , r[N];
int n , k;

bool ok(int m)
{
    ll cnt = 0;

    for (int i = 0 ; i < n ; i ++)
    {
        if (m < l[i])
            continue;
        
        cnt += min(r[i] , m) - 1ll * l[i] + 1;
    }

    return cnt > k;
}

void solve()
{
    cin >> n >> k;

    for (int i = 0 ; i < n ; i ++)
        cin >> l[i] >> r[i];

    ll L = -2e9, R = 2e9;
    while (L < R)
    {
        ll mid = L + (R - L) / 2;

        if (ok(mid))
            R = mid;
        else 
            L = mid + 1;
    }

    cout << L << endl;
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