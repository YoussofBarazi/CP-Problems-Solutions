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
    string s;
    cin >> s;

    if (is_sorted(s.begin(), s.end()))
    {
        cout << "0" << endl;
        return;
    }

    ll ans = 1e18 , cnt1 = 0 , cnt0 = 0;
    vl t;

    for (size_t i = 0; i < s.size(); i++)
    {
        cnt1 += s[i] == '1';
    }

    for (int i = s.size() - 1; i >= 0; i--)
    {
        ll x = 1e12 + 1;
        x *= (cnt1 + cnt0);

        if (i > 0 && s[i] < s[i - 1]) x --;
    
        ans = min(ans , x);
        cnt1 -= s[i] == '1';
        cnt0 += s[i] == '0';
    }

    ans = min(ans * 1.0 , (1e12 + 1) * cnt0);
    
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