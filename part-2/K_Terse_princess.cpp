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
    int n , a , b;
    cin >> n >> a >> b;

    vi ans(n + 3 , 1);
    int sum = 1;
    int mx = 1;
    
    if (a == n - 1 && n != 1)
    {
        cout << -1 << endl;
        return;
    }
    
    for (size_t i = 1; i < n; i++)
    {
        if (b > 0)
        {
            b --;
            ans[i] = sum + 1;
            sum += ans[i];
            mx = max(ans[i] , mx);
        }
    }
    for (int i = n - a ; i < n ; i ++)
    {
        if (a > 0)
        {
            ans[i] = mx + 1;
            mx ++;
            a --;
        }
    }
    if (ans[n - 1] > 50000)
    {
        cout << -1 << endl;
        return;
    }
    
    for (int i = 0 ; i < n ; i ++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    IOS;

    int t = 1;
    //cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}