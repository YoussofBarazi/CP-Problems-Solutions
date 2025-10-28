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

const int SUM = 500, N = 109;

int dp[N][SUM + 9][SUM + 9];
int a[N], power[N];
int sum;
int n;

int sol(int i = 0, int sum1 = 0, int sum2 = 0) {
    if (i == n) {
        return (sum1 == sum2 && sum1 == sum / 3) ? 0 : 1e3;
    } else if (sum1 > sum / 3 || sum2 > sum / 3) {
        return 1e3;
    }

    int &ret = dp[i][sum1][sum2];

    if (ret != -1) {
        return ret;
    } 
    ret = 1e3;

    if (a[i] == 1) {
        ret = min({ret, sol(i + 1, sum1 + power[i], sum2), sol(i + 1, sum1, sum2 + power[i]) + 1, sol(i + 1, sum1, sum2) + 1});
    } else if (a[i] == 2) {
        ret = min({ret, sol(i + 1, sum1 + power[i], sum2) + 1, sol(i + 1, sum1, sum2 + power[i]), sol(i + 1, sum1, sum2) + 1});
    } else {
        ret = min({ret, sol(i + 1, sum1 + power[i], sum2) + 1, sol(i + 1, sum1, sum2 + power[i]) + 1, sol(i + 1, sum1, sum2)});
    }

    return ret;
}

void solve()
{
    cin >> n;


    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i] >> power[i];
        sum += power[i];
    }

    if (sum % 3) {
        cout << -1 << endl;
        return ;
    }

    memset(dp, -1, sizeof dp);
    int ans = sol();
    if (ans >= 1e3) {
        ans = -1;
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