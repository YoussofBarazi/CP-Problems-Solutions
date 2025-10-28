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

ll balance[N][50];
int a[N] , n , k;

ll POW(ll x, ll y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;

    long long ans = POW(x, y / 2);

    if (y & 1)
        return ans * ans * x;
    return ans * ans;
}

ll dp(int i , int half_count)
{
    if (i == n || half_count == 50)
        return 0;

    ll &ret = balance[i][half_count];

    if (ret != -1)
        return ret;

    ret = max(dp(i + 1 , half_count) - k + a[i] / POW(2 , half_count) , dp(i + 1 , half_count + 1) + a[i] / POW(2 , half_count + 1));

    return ret; 
}

void solve()
{
    cin >> n >> k;

    for (int i = 0 ; i < n ; i ++)
        cin >> a[i];

    for (int i = 0 ; i < n ; i ++)
        for (int j = 0 ; j < 50 ; j ++)
            balance[i][j] = -1;

    cout << dp(0 , 0) << endl;
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