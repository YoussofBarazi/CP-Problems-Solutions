#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define oo INT_MAX
#define OO LONG_MAX
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 202;

int n, k;
int a[202][202];
int b[202][202];

int add_coat()
{
    int L = 1e5, R = 0, I = 1e5, J = 0, L2 = 1e5, I2 = 1e5;

    for (size_t j = 1; j < N; j++)
    {
        for (size_t i = 1; i < N; i++)
        {
            b[i][j] += b[i - 1][j];
        }
    }

    bool ok = false;
    int add = 0;
    for (size_t l = 1; l < N; l++)
    {
        for (size_t r = l; r < N; r++)
        {
            int sum = 0, mn = 1e5;
            for (size_t j = 1; j < N; j++)
            {
                int x = b[r][j] - b[l - 1][j];
                sum += x;

                if (sum - mn > add)
                {
                    add = sum - mn;
                    R = r, J = j;
                    L2 = L, I2 = I;
                    ok = true;
                }

                if (mn > sum)
                {
                    mn = sum;
                    L = l, I = j;
                }
            }
        }
    }

    if (ok)
        for (size_t i = L2; i <= R; i++)
        {
            for (size_t j = I2; j <= J; j++)
            {
                a[i][j]++;
            }
        }

    return add;
}

void make_k()
{
    for (size_t i = 1; i < N; i++)
    {
        for (size_t j = 1; j < N; j++)
        {
            b[i][j] = (a[i][j] == (k - 1));
            b[i][j] -= (a[i][j] == k);
        }
    }
}
void solve()
{
    cin >> n >> k;

    for (size_t i = 0; i < n; i++)
    {
        int x, y, X, Y;
        cin >> x >> y >> X >> Y;

        x++, X++, y++, Y++;

        a[x][y]++;
        a[x][Y]--;
        a[X][y]--;
        a[X][Y]++;
    }

    int ans = 0;

    for (size_t i = 1; i < N; i++)
    {
        for (size_t j = 1; j < N; j++)
        {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            ans += (a[i][j] == k);
        }
    }

    make_k();
    ans += add_coat();

    make_k();
    ans += add_coat();

    cout << ans << endl;
}

int main()
{
    IOS;

    // freopen("paintbarn.in", "r", stdin);
    // freopen("paintbarn.out", "w", stdout);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}