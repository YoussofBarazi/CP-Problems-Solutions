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

map <int , int> primefactor;
void primeFactors(int n)
{
    while (n % 2 == 0)
    {
        primefactor[2] ++;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            primefactor[i] ++;
            n = n / i;
        }
    }

    if (n > 2)
        primefactor[n] ++;
}


void solve()
{
    int n;
    cin >> n;

    primefactor.clear();
    primeFactors(n);

    ll ans = 0;        

    while (primefactor.size())
    {
        int a = 1 , p = n;
        
        for (auto x : primefactor)
        {
            a *= x.F , p = min(p , x.S);
        }

        vi del;
        for (auto x : primefactor)
        {
            primefactor[x.F] -= p;
            if (x.S == 0)
            {
                del.pb(x.F);
            }
        }

        for (auto x : del)
            primefactor.erase(x);

        ans += a * p;
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