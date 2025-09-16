#include <bits/stdc++.h>

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
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 200009;

ll ans = 0;
bool ok(ll t, ll h) {
    return (t - (t + ans % 3) / 3) >= h - ((t + ans % 3) / 3) * 3;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0 ; i < n ; i ++) {
        int h;
        cin >> h;

        ll l = 0, r = 2e14;
        
        while (l < r) {
            ll mid = (l + r) / 2;

            if (ok(mid, h)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        ans += l;
    }

    cout << ans << endl;
}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}