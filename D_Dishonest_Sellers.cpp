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

    vi a(n) , b(n);
    vector <pi> x(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> b[i];
        x[i] = {a[i] - b[i] , i};
    }
    Sort(x);
    
    int ans = 0;
    for (size_t i = 0; i < k; i++)
    {
        ans += a[x[i].S];        
    }
    for (size_t i = k; i < n; i++)
    {
        if (a[x[i].S] <= b[x[i].S])
            ans += a[x[i].S];
        else
            ans += b[x[i].S];
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