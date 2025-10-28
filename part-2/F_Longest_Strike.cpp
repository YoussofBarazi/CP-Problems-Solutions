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
    int n , k;
    cin >> n >> k;

    vi a(n);
    map <int,int> m;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]] ++;
    }
    
    set <int> s;
    for (auto x : m)
    {
        if (x.S >= k)
        {
            s.insert(x.F);
        }
    }
    
    int mn = 0 , mx = 0;
    pi ans = {mn , mx};

    for (auto x : s)
    {
        start :
        if (mn == 0)
        {
            mn = x;
            mx = x;
        }
        if (x != mx)
        {
            mn = 0;
            goto start;
        }
        if (mx - mn >= ans.S - ans.F)
        {
            ans.F = mn;
            ans.S = mx;
        }
        mx ++;
    }

    if (ans.F == 0)
    {
        cout << -1 << endl;
    }
    else 
    {
        cout << ans.F << " " << ans.S << endl;
    }
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