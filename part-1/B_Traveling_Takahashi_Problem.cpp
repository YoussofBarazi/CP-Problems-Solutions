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

long double dist(int x1 , int y1 , int x2 , int y2) {
    return sqrtl (1ll * (x2 - x1) * (x2 - x1) + 1ll * (y2 - y1) * (y2 - y1));
}

void solve()
{
    int n;
    cin >> n;

    int x1 = 0 , y1 = 0;

    long double ans = 0;

    for (int i = 0 ; i < n ; i ++) {
        int x2 , y2;
        cin >> x2 >> y2;

        ans += dist(x1 , y1 , x2 , y2);
        x1 = x2;
        y1 = y2;
    }

    ans += dist(0 , 0 , x1 , y1);

    cout << fixed << setprecision(20);
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