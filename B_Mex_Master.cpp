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

    int cnt1 = 0 , cnt0 = 0 , cnt2 = 0;
    for (size_t i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        cnt0 += x == 0;
        cnt1 += x == 1;
        cnt2 += x > 0;
    }

    int ans = 0;
    if (cnt0 != n && cnt0 + cnt1 == n)
    {
        if (cnt1 + 1 >= cnt0)
        {
            ans = 0;
        }
        else
        {
            ans = 2;
        }
    }
    else if (cnt2 + 1 >= cnt0)
    {
        ans = 0;
    }
    else 
    {
        ans = 1;
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