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
    ll n , s;
    cin >> n >> s;

    vl a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    bool done = false;
    ll time = 0 , ans = -1 , mx = 0;
    for (size_t i = 0; i < n; i++)
    {
        time += a[i];
        if (a[mx] < a[i]) mx = i;

        if (time > s)
        {
            if (done)
            {
                break;
            }

            ans = mx;
            time -= a[mx];
            done = true;
        }
    }
    
    cout << ans + 1 << endl;
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