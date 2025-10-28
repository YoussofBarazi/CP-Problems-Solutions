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

vi primefactor;
void primeFactors(int n)
{
    while (n % 2 == 0)
    {
        primefactor.pb(2);
        n = n / 2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            primefactor.pb(i);
            n = n / i;
        }
    }

    if (n > 2)
        primefactor.pb(n);
}

void solve()
{
    int n;
    cin >> n;

    primeFactors(n);

    int a , b , c;
    a = primefactor.front();
    b = c = 1;
    
    for (size_t i = 1; i < primefactor.size() - 1; i++)
    {
        b *= primefactor[i];
        if (i == primefactor.size() - 2 && primefactor.back() == primefactor.front())
        {
            b /= primefactor[i];
            c *= primefactor[i];
        }
    }
    c *= primefactor.back();

    if (c == 1 || b == 1 || a == b || a == c || b == c || a * b * c != n)
    {
        cout << "NO" << endl;
    }
    else 
    {
        cout << "YES" << endl;
        cout << a << " " << b << " " << c << endl;
    }    

    primefactor.clear();
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