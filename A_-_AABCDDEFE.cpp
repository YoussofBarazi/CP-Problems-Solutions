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

    ll a[] = {110000000 , 1000000 , 100000 , 11000 , 101 , 10};
    reverse(a , a + 6);

    ll ans = 110000000;
    int i = 0;
    n --;
    while (n)
    {
        ans += a[i] * (n % 10);
        i ++;
        n /= 10;
    }

    cout << ans << endl;
}

int main()
{
    IOS;

    int t = 1;
//    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}