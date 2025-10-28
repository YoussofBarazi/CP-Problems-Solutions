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
    int n , l , r;
    cin >> n >> l >> r;

    vi a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int j = 0 , ans = 0;
    for (int i = 0; i < n; i++)
    {
        bool yes = false;
        j = i;
        if (a[i] >= l && a[i] <= r)
        {
            while (j < n && (a[j] <= r && a[j] >= l)) j ++;
            yes = true;
        }
        if(yes) ans = max(ans , j - i);
        i = j;
    }

    cout << ans << endl;
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