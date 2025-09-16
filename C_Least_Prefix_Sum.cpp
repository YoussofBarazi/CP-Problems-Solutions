#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
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

    vl a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vl ps(n);
    ps[0] = a[0];
    for (size_t i = 1; i < m; i++)
    {
        ps[i] = ps[i - 1] + a[i];
    }
    
    priority_queue <ll> l;


    int ans = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        while (l.size() && ps[i] < ps[m - 1])
        {
            ps[m - 1] -= 2 * l.top();
            l.pop();
            ans ++;
        }
        l.push(a[i]);
    }
    
    priority_queue<ll, vector<ll>, greater<ll>> r;
    
    for (size_t i = m; i < n; i++)
    {
        ps[i] = ps[i - 1] + a[i];
        r.push(a[i]);
        while (r.size() && ps[i] < ps[m - 1])
        {
            ps[i] -= 2 * r.top();
            r.pop();
            ans ++;
        }
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