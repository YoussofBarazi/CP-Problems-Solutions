#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pll pair<long long, long long>
#define pii pair<int, int>
#define mii map<int, int>
#define mll map<long long, long long>
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define rev greater<int>()
#define RF(F) freopen(F, "r", stdin)
#define WF(F) freopen(F, "w", stdout)
using namespace std;

const ll INF = 1e9;
const int eps = 1e-7;
const int mod = 1e9 + 7;
const int N = 500 + 7;

char c[N][N];
int n, m;
int a[N];
int col = 0;
int vis[N][N], mem[N][N];
int pon[N];

int dp(int i, int j)
{
    if (j < 0 || m <= j)
        return -INF;

    if (i == n)
        return pon[j];

    if (vis[i][j] == col)
        return mem[i][j];

    vis[i][j] = col;

    int ans = -INF;

    if (c[i][j] == '.')
        ans = dp(i + 1, j);
    else
    {
        ans = max(ans, dp(i + 1, j + 1));
        ans = max(ans, dp(i + 1, j - 1));
        ans = max(ans, dp(i + 1, j));
    }

    return mem[i][j] = ans;
}

void solve(int testCase)
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%s", c[i]);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &pon[i]);
    }

    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans += 1ll * a[i] * dp(0, i);
    }

    printf("%lld\n", ans);
}

int main()
{
    RF("balls.in");

    int testCase = 1;

    scanf("%d", &testCase);

    for (int T = 1; T <= testCase; T++)
    {
        col = T;
        solve(T);
    }

    return 0;
}
