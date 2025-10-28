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



void solve()
{
    int n;
    cin >> n;

    vector <ll> q(n), r(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> q[i] >> r[i];
    }
    int Q;
    cin >> Q;

    while (Q--) {
        ll t, d;
        cin >> t >> d;
        t--;

        ll l = 0, h = 1e9; 
        while (l < h) {
            ll mid = (l + h) / 2;
            if (mid * q[t] + r[t] >= d) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }

        cout << l * q[t] + r[t] << endl;
    }
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