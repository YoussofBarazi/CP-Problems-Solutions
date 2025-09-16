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

const int N = 20009;

string s[N];
ll a[N];
char b[N];

void solve()
{
    int n;
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        cin >> s[i] >> a[i] >> b[i];
    }

    ll l = -2e9, r = 2e9, m;

    for (size_t i = 0; i < n; i++)
    {
        if (b[i] == 'Y')
            if (s[i] == ">=") l = max(a[i], l);
            else if (s[i] == "<=") r = min(r, a[i]);
            else if (s[i] == ">") l = max(a[i] + 1 , l);
            else r = min(a[i] - 1 , r);
        else 
            if (s[i] == ">=") r = min(a[i] - 1 , r);
            else if (s[i] == "<=") l = max(a[i] + 1 , l);
            else if (s[i] == ">") r = min(r, a[i]);
            else l = max(a[i], l);
    }

    if (l > r)
    {
        cout << "Impossible" << endl;
    }
    else 
    {
        cout << l << endl;
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