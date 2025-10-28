#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

double x[N] , v[N];
int n;

bool ok(double t)
{
    double l = 0 , r = 1e9;

    for (int i = 0 ; i < n ; i ++)
    {
        l = max(l , x[i] - v[i] * t);
        r = min(r , x[i] + v[i] * t);
    }

    return r - l > 0;
}

void solve()
{
    cin >> n ;

    for (int i = 0 ; i < n ; i ++)
        cin >> x[i];
    
    for (int i = 0 ; i < n ; i ++)
        cin >> v[i];

    double l = 0 , r = 1e9;
    for (int i = 0 ; i < 100 ; i ++)
    {
        double mid = (l + r) / 2;

        if (ok(mid))
            r = mid;
        else 
            l = mid;
    }

    cout << fixed << setprecision(12) << l << endl;
}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}