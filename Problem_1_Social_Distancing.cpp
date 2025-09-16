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

pl a[N];
int n , m;

bool ok(ll d)
{
    int j = 0 ;
    ll dis = a[0].F;

    for (int i = 0 ; i < n ; i++)
    {
        while (j < m && dis > a[j].S)
            j ++;
        
        if (j == m)
            return false;
        
        dis = max(a[j].F , dis);
        dis += d;
    }

    return true;
}

void solve()
{
    cin >> n >> m;

    for (int i = 0 ; i < m ; i ++)
        cin >> a[i].F >> a[i].S;

    sort(a , a + m);

    ll l = -1 , r = 1e18;

    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        
        if (ok(mid))
            l = mid;
        else 
            r = mid;
    }

    cout << l << endl;
}

int main()
{
    freopen("socdist.in" , "r" , stdin);
    freopen("socdist.out" , "w" , stdout);

    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}