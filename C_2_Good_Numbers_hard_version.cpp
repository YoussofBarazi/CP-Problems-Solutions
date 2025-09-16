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
    ll n;
    cin >> n;

    vl a;
    while (n)
    {
        a.pb(n % 3);
        n /= 3;
    }
    reverse(a.begin() , a.end());

    ll ans = 0;
    int i = a.size() - 1;
    while (i >= 0 && a[i] != 2) i --;

    if (i != -1)
    {
        while (i >= 0 && a[i] != 0) a[i] %= 2 , i --;

        if (i == -1)
        {
            ans += pow(3 , a.size());
        }
        else a[i] = 1;
    }
    for (size_t i = 0; i < a.size(); i++)
    {
        ans += a[i] * pow(3 , a.size() - i - 1);
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