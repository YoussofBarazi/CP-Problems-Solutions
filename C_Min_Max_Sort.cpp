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

    vi a(n + 1 , n);
    for (size_t i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        a[x] = i;
    }

    int ans = (n + 1) / 2 , cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > a[i - 1])
        {
            cnt ++;
        }
        else 
        {
            cnt = 1;
        }
        ans = min(ans , max(i - cnt , n - i));
    }
    
    cout << ans << endl;
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