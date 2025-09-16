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
    int n , k , q;
    cin >> n >> k >> q;

    vi a(2e5 + 9 , 0);
    vi b = a;
    for (size_t i = 0; i < n; i++)
    {
        int l , r;
        cin >> l >> r;

        a[l] ++;
        a[r + 1] --;
    }
    
    for (size_t i = 1; i < 2e5 + 9; i++)
    {
        a[i] += a[i - 1];
    }
    
    int cnt = 0;
    for (size_t i = 0; i < 2e5 + 9; i++)
    {
        if (a[i] >= k) cnt ++;
        b[i] = cnt;
    }
    
    for (size_t i = 0; i < q; i++)
    {
        int l , r;
        cin >> l >> r;

        cout << b[r] - b[l - 1] << endl;
    }
    
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