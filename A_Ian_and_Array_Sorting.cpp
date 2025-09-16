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
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend() 
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
    ll sum = 0;
    bool state = true;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        if (state) sum -= a[i];
        else sum += a[i];

        state = !state;
    }
    
    string ans;
    if (n % 2 || sum >= 0)
    {
        ans = "YES";
    }
    else 
    {
        ans = "NO";
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