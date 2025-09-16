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

    vector <pi> a(n);
    vi ind;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i].F >> a[i].S;
        ind.pb(a[i].S);
        ind.pb(a[i].F);
    }
    sort(all(ind));

    vi prefix(2 * (n + 1) , 0);
    for (size_t i = 0; i < n; i++)
    {
        int x = lower_bound(all(ind) , a[i].F) - ind.begin();
        int y = lower_bound(all(ind) , a[i].S) - ind.begin();

        prefix[x] ++;
        prefix[y] --;
    }
    
    int ans = prefix[0];
    for (size_t i = 1; i < prefix.size() - 1; i++)
    {
        prefix[i] += prefix[i - 1];
        ans = max(ans , prefix[i]);
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