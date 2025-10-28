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
#define Sort(a) sort(a.begin(), a.end())
#define Rsort(a) sort(a.rbegin(), a.rend())
#define UB(a, t) upper_bound(a.begin(), a.end(), t) - a.begin()
#define LB(a, t) lower_bound(a.begin(), a.end(), t) - a.begin()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

void solve()
{
    int n, m;
    cin >> n;

    vl a(n);
    ll sum1 = 0, sum2 = 0;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        sum1 += a[i];
    }
    cin >> m;

    vl b(m);
    for (size_t i = 0; i < m; i++)
    {
        cin >> b[i];
        sum2 += b[i];
    }
    
    if (sum1 != sum2)
    {
        cout << -1 << endl;
        return;
    }

    sum1 = sum2 = 0;
    int i = 0, j = 0, ans = 0 , cnt = n + m;

    while (cnt > 0)
    {
        while (i < n && (sum1 < sum2 || sum1 == 0))
            sum1 += a[i], i++;

        while (j < m && (sum1 > sum2))
            sum2 += b[j], j++;


        if (sum1 > 0 && sum1 == sum2)
        {
            ans++;
            sum1 = sum2 = 0;
        }
        
        cnt --;
    }

    cout << ans << endl;
}

int main()
{
    IOS;

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}