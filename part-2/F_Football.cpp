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
    int n , a , b;
    cin >> n >> a >> b;

    vi f , s;
    while (n > 0 && a > 0)
    {
        f.pb(1) , s.pb(0);
        n -- , a --;
    }
    while (n > 0 && b > 0)
    {
        f.pb(0) , s.pb(1);
        n -- , b --;
    }
    while (n > 0 && !a && !b)
    {
        f.pb(0) , s.pb(0);
        n -- ;
    }

    if (a > 0) f.front() += a;
    if (b > 0)
    {
        if (s.size() >= 2)
        {
            if (f.back() == b + s.back())
            {
                f.back() --;
                f[f.size() - 2] ++;
            }
        }
        s.back() += b;
    }
    
    for (size_t i = 0; i < f.size(); i++)
    {
        if (f[i] == s[i]) n ++; 
    }

    cout << n << endl;
    for (size_t i = 0; i < f.size(); i++)
    {
        cout << f[i] << ":" << s[i] << endl; 
    }
}

int main()
{
    IOS;

    int t = 1;
//    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}