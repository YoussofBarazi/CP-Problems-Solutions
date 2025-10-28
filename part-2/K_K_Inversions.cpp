#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define F first
#define S second
#define ll long long
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
using namespace __gnu_pbds;
int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 1000009;

void solve()
{
    ll n, k;
    cin >> n >> k;

    ordered_set s;

    for(int i = 1 ; i <= n ; i ++) {
        s.insert(i);
    }

    int x = n;
    while (x > 0) {
        ll t = max(0ll, k - 1ll * (x - 1) * (x - 2) / 2);
        int ans = *s.find_by_order(t);
        cout << ans << " ";
        
        s.erase(ans);
        x--;
        k -= t;
    } cout << endl;
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