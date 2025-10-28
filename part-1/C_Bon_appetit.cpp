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
    int n , m;
    cin >> n >> m;

    vi a(n) , c(m);
    map <int,int> x;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        x[a[i]] ++;
    }
    for (size_t i = 0; i < m; i++)
    {
        cin >> c[i];
    }
    Rsort(c);
    int ans = 0;
    for (size_t i = 0; i < m; i++)
    {
        int mx = 0 , ind = 0;
        for (auto i : x)
        {
            if (i.S > mx)
            {
                ind = i.F;
                mx = i.S;
            }
        }
        ans += min(c[i] , mx);
        x[ind] -= min(c[i] , mx);
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