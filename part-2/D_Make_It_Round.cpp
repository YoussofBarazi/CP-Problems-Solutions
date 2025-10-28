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
    ll n , m;
    cin >> n >> m;

    ll tmp = n , cnt2 = 0 , cnt5 = 0 , k = 1;
    while (n && n % 2 == 0)
    {
        cnt2 ++;
        n /= 2;
    } 
    while(n && n % 5 == 0)
    {
        cnt5 ++;
        n /= 5;
    }

    while (cnt2 < cnt5 && k * 2 <= m)
    {
        k *= 2;
        cnt2 ++;
    }
    while (cnt2 > cnt5 && k * 5 <= m)
    {
        k *= 5;
        cnt5 ++;
    }
    while (k * 10 <= m)
    {
        k *= 10;
    }
    n = tmp;

    cout << ((k > 1)? k *= m / k , k * n : n * m) << endl;
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