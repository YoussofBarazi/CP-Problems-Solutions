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
    int a , b , c , d;
    cin >> a >> b >> c >> d;

    int ans = a + min(b , c) * 2;

    int x = min(b , c); 
    b -= x;
    c -= x;

    if (a == 0 && ans > 0) 
        ans = 1 , c = 0 , b = 0 , d = 0;

    if (b)
        ans += min(a , b) , x = min(a , b) , b -= x , a -= x;
    else if (c)
        ans += min(a , c) , x = min(a , c) , c -= x , a -= x;
    
    ans += min(a , d) , d -= min(a , d);

    if (d > 0 || b > 0 || c > 0) ans ++;

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