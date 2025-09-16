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

const int N = 200009;

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int d = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (i > m)
            break;

        if (n % i == 0)
        {
            d = i;
            break;
        }
    }

    if (n % d == 0 && d <= m && m != 1 & n != 1)
        printf("NO\n");
    else
        printf("YES\n");
}

int main()
{
    // IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}