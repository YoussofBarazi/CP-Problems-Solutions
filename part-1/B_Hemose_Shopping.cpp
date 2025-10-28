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
    int n , x ;
    cin >> n >> x;

    vi a(n) , b(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    Sort(b);
    if (n / 2 >= x || is_sorted(a.begin() , a.end()))
    {
        cout << "YES" << endl;
        return;
    }
    
    if (x >= n)
    {
        cout << "NO" << endl;
        return;
    } 

    for (size_t i = n - x; i <= x - 1; i++)
    {
        if (b[i] != a[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
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