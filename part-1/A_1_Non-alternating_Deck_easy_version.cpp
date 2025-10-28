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

    ll alice = 1 , bob = 0;
    n --;
    ll i = 2;
    while (n > 0)
    {
        if (n >= 2 * i + 1)
        {
            bob += i + 1 + i;
            n -= 2 * i + 1;
            i += 2;
        }
        else
        {
            bob += n;
            n = 0;
        }
        
        if (n >= i * 2 + 1)
        {
            alice += i + 1 + i;
            n -= 2 * i + 1;
            i += 2;
        }
        else
        {
            alice += n;
            n = 0;
        }
    }

    cout << alice << " " << bob << endl;
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