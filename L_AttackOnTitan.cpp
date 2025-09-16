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
    int n;
    cin >> n;

    vl a(n + 1) , sum(n + 1 , 0);
    ll mx = 0;
    for (size_t i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = a[i] + sum[i - 1];
        mx = max(a[i] , mx);
    }

    if (mx >= sum.back())
    {
        cout << "NO" << endl;
        return;
    }

    int j = 0;
    ll sum2 = mx;
    for (int i = 1; i <= n; i++)
    {
        j = max(j , i + 1);
        while (j <= n - (i - 1 == 0) && sum[j] > sum[i - 1]) 
        {
            sum2 = max(sum[j] - sum[i - 1] , sum2);
            j ++;
        }
        sum2 = max(sum[j - 1] - sum[i - 1] , sum2);
    }

    if (sum2 >= sum.back())
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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