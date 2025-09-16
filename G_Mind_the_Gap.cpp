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
    int n, s;
    cin >> n >> s;

    vi a(n), b(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        cin >> b[i];
    }

    int h = 0, m = 0;
    m += s;
    h += m / 60;
    m %= 60;

    if (a.front() > h || (a.front() == h && m < b.front()))
    {
        cout << 0 << " " << 0 << endl;
        return;
    }

    for (size_t i = 0; i < n - 1; i++)
    {
        int h = a[i] , m = b[i];
        int h1 = a[i] , m1 = b[i];
        
        m += s * 2 + 1;
        h += m / 60;
        m %= 60;

        m1 += s + 1;
        h1 += m1 / 60;
        m1 %= 60;

        if (a[i + 1] > h || (a[i + 1] == h && m < b[i + 1]))
        {
            cout << h1 << " " << m1 << endl;
            return;
        }
    }

    h = a.back(), m = b.back();

    m += s + 1;
    h += m / 60;
    m %= 60;

    cout << h << " " << m << endl;
}

int main()
{
    IOS;

    int t = 1;
    //cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}