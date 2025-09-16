#include <bits/stdc++.h>

#define F first
#define S second
#define ll long long
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 200009;

int n , c;
ll pref[N];
pii a[N];
int ans = 0;

bool ok(int ndx1 , int ndx2)
{
    ll x = pref[ndx1];
    bool after = true;

    if (ndx1 >= ndx2 + 1)
        x -= a[ndx2].F , after = false;

    x += a[ndx2].S;

    if (x <= c)
        ans = max(ans , ndx1 + after);

    // cout << ndx1 << " " << ndx2 << " " << x << " " << c << endl;

    return x <= c;
}

void solve()
{
    cin >> n >> c;

    for (int i = 0 ; i < n ; i ++)
    {
        int x;
        cin >> x;

        a[i] = {x + min(i + 1 , n - i) , x + i + 1};
    }

    sort(a , a + n);

    for (int i = 1 ; i <= n ; i ++)
    {
        pref[i] = pref[i - 1] + a[i - 1].F;
    }

    ans = 0;

    for (int i = 0 ; i < n ; i ++)
    {
        int l = 0 , r = n ; 

        while (l <= r)
        {
            int mid = (l + r) >> 1;

            if (ok(mid , i))
                l = mid + 1;
            else 
                r = mid - 1;
        }    
    }

    cout << ans << endl;
}

int main()
{
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}