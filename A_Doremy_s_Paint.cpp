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
    int n;
    cin >> n;

    vi a(n);
    map <int , int> m;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vi v(n);
    int cnt = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (!m[a[i]])
        {
            cnt ++;
        }
        m[a[i]] ++;
        v[i] = cnt;
    }

    int l = 0 , r = n - 1;
    int mxl = 1, mxr = n , mx = 0;
    while (l <= r)
    {
        int x = r - l - v[r];
        if (l > 0) x += v[l - 1];

        if (mx < x)
        {
            mxr = r + 1;
            mxl = l + 1;
            mx = x;
        }
        
        if (l + 1 < n && v[l] == v[l + 1]) r --;
        else l ++;
    }

    cout << mxl << " " << mxr << endl;
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