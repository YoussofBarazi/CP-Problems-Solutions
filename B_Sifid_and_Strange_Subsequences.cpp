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

    int mx = -oo , cnt0 = 0;
    vi neg , pos;
    for (size_t i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mx = max (mx , a);
        if (a == 0) cnt0 ++;
        else if (a < 0) neg.pb(a);
        else pos.pb(a);
    }
    
    int ans = 1;
    if (mx <= 0)
    {
        ans = n;
    }
    else
    {
        int mn = oo;

        Sort(neg);
        Sort(pos);

        for (size_t i = 1; i < neg.size(); i++)
        {
            mn = min (mn , abs(neg[i] - neg[i - 1]));
        }
        if (pos.front() <= mn)
        {
            ans = (unique(neg.begin() , neg.end()) - neg.begin()) + 1;
            if (neg.size() && -neg.back() >= pos.front() && cnt0)
            {
                ans ++;
            }
        }
        if (cnt0) ans = max (ans , 2);
        ans = max (ans , (int)neg.size() + cnt0);
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