#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define pb push_back
#define y first
#define x second
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
    cin >> n ;

    vector <pair<int , int>> a(n);

    for (auto &w : a)
        cin >> w.x >> w.y;

    sort(all(a));

    int l = 0 , r = n - 1 , ans = 0;

    while (l < r)
    {
        int t = min(a[l].x , a[r].x);
        ans = max(ans , a[l].y + a[r].y);

        a[l].x -= t;
        a[r].x -= t;

        if (a[l].x == 0)
            l ++;
        if (a[r].x == 0)
            r --;
    }

    cout << ans << endl;
}

int main()
{
    freopen("pairup.in" , "r" , stdin);
    freopen("pairup.out" , "w" , stdout);

    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}