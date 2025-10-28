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
    int n ,m;
    cin >> n >> m;
    
    vector <priority_queue<ll>> a(m);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            a[j].push(x);
        }       
    }

    vl sum(n);
    ll cnt1 = n - 1 , cnt2 = 0 , ans = 0;
    for (size_t i = 0; i < m; i++)
    {
        while (a[i].size() > 0)
        {
            sum[n - a[i].size()] += a[i].top();
            a[i].pop();
        }   
    }
    
    for (size_t i = 0; i < n; i++)
    {
        ans += sum[i] * cnt1;
        ans -= sum[i] * cnt2;
        cnt1 -- , cnt2 ++;
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