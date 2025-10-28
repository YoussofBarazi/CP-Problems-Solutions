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
    string s;
    cin >> n >> k >> s;

    vi a;
    for (size_t i = 0; i < n; i++)
    {
        if (s[i] == '1') a.pb(i);
    }
    int ans = 0;
    
    if (!a.size())
    {
        ans = max(ans , (n + k) / (k + 1));
    }
    else if (a.size())
    {
        ans += a.front() / (k + 1); 
        ans += (n - a.back() - 1) / (k + 1);
    }

    for (size_t i = 1; i < a.size(); i++)
    { 
        ans += (a[i] - a[i - 1] - 1 - k) / (k + 1);    
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