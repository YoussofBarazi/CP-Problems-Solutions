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

const int N = 20;

string s[N];
bool vis[N][N];
int h, w, k;

ll calc(int i, int j, int k) {
    if (0 > i || i >= h || 0 > j || j >= w || vis[i][j] || s[i][j] == '#') {
        return 0;
    } else if (k == 0) {
        return 1;
    } 

    vis[i][j] = true;
    ll cnt = 0;
    for (int t = 0 ; t < 4 ; t ++) {
        cnt += calc(i + dx[t], j + dy[t], k - 1);
    }
    vis[i][j] = false;
    return cnt;
}

void solve()
{
    cin >> h >> w >> k;

    for (int i = 0 ; i < h ; i ++) {
        cin >> s[i];
    }   

    ll ans = 0;

    for (int i = 0 ; i < h ; i ++) {
        for (int j = 0 ; j < w ; j ++) {
            ans += calc(i, j, k);
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