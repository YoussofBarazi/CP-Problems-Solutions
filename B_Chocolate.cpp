#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
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

    vector <int> ind;
    for (int i = 0 ; i < n ; i ++)
    {
        int x;
        cin >> x;

        if (x)
            ind.pb(i);
    }

    ll ans = ind.size() > 0;
    for (int i = 1 ; i < ind.size() ; i ++)
    {
        ans *= 1ll * (ind[i] - ind[i - 1]);
    }

    cout << ans << endl;
}

int main()
{
    IOS;

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}