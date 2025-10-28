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
    int n , m;
    cin >> n >> m;

    vi seat(n * m + 1);
    vector <pi> a(n * m);
    for (size_t i = 0; i < m; i++)
    {
        cin >> a[i].F;
        a[i].S = i;
    }
    sort(all(a));

    int num = 1;
    for (size_t i = 0; i < n * m; i++)
    {
        if (i + 1 < n * m && a[i].F == a[i + 1].F)
        {
            vector <pi> rep;
            while (i + 1 < n * m && a[i].F == a[i + 1].F)
            {
                rep.pb(a[i]);
                i ++;
            }
            rep.pb(a[i]);
            for (int i = rep.size() - 1; i >= 0; i--)
            {
                seat[num ++] = rep[i].S;
            }
        }
        else seat[num ++] = a[i].S;
    }
    multiset <pi> s;
    
    int ans = 0;
    for (size_t i = 1; i <= n * m; i++)
    {
        if (s.size() % m == 0)
            s.clear();

        s.insert(a[seat[i]]);
        auto x = s.begin();
        int cnt = 1;
        while (*x != a[seat[i]]) x ++ , cnt ++; 
        ans += --cnt;
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