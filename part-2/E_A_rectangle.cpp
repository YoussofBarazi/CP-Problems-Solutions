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
    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll ans = ((y2 - y1 + 2) / 2) * ((x2 - x1 + 2) / 2);
    x1 ++ , x2 -- , y1 ++ , y2 --;
    ans += ((y2 - y1 + 2) / 2) * ((x2 - x1 + 2) / 2);

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