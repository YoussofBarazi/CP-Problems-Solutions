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
    int n , q;
    cin >> n >> q;

    int l = 1 , r = 2;
    ll ans = 0;
    while (q --) {
        char c; int pos;
        cin >> c >> pos;

        if (c == 'R') {
            if (r <= pos) {
                if (r <= l && l <= pos) {
                    ans += r + n - pos;
                } else {
                    ans += pos - r;
                }
            } else {
                if (pos <= l && l <= r) {
                    ans += n - r + pos;
                } else {
                    ans += r - pos;
                } 
            }
            r = pos;
        } else {
            if (l <= pos) {
                if (l <= r && r <= pos) {
                    ans += l + n - pos;
                } else {
                    ans += pos - l;
                }
            } else {
                if (pos <= r && r <= l) {
                    ans += n - l + pos;
                } else {
                    ans += l - pos;
                }
            }
            l = pos;
        }
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