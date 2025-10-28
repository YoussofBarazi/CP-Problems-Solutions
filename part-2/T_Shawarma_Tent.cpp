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
#define Sort(a) sort(a.begin(), a.end())
#define Rsort(a) sort(a.rbegin(), a.rend())
#define UB(a, t) upper_bound(a.begin(), a.end(), t) - a.begin()
#define LB(a, t) lower_bound(a.begin(), a.end(), t) - a.begin()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

void solve()
{
    int n , x , y;
    cin >> n >> x >> y;

    vi a(n) , b(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    
    pi ans;
    int cnt1 = 0 , cnt2 = 0 , cnt3 = 0 , cnt4 = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (x - 1 >= a[i])
        {
            cnt1 ++;
        }
        if (y + 1 <= b[i])
        {
            cnt2 ++;
        }
        if (x + 1 <= a[i])
        {
            cnt3 ++;
        }
        if (y - 1 >= b[i])
        {
            cnt4 ++;
        }
    }
    
    int mx = 0;
    if (mx < cnt1) 
    {
        mx = cnt1;
        ans = {x - 1 , y};
    }
    if (mx < cnt2)
    {
        mx = cnt2;
        ans = {x , y + 1};
    }
    if (mx < cnt3)
    {
        mx = cnt3;
        ans = {x + 1 , y};
    }
    if (mx < cnt4)
    {
        mx = cnt4;
        ans = {x , y - 1};
    }

    cout << mx << endl;
    cout << ans.F << " " << ans.S << endl;
}

int main()
{
    IOS;

    int t = 1;
    //cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}