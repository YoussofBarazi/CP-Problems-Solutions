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

set <int> s;

void get(int n)
{
    for (size_t i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
            s.insert(i);
    }    
}

void solve()
{
    int n , m , k;
    cin >> n >> m >> k;

    vector <int> a(n + 1 , 0) , b(m + 1 , 0);
    for (size_t i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        a[i] = a[i - 1] + x;
    }
    for (size_t i = 1; i <= m; i++)
    {
        int x;
        cin >> x;

        b[i] = b[i - 1] + x;
    }
    
    get(k);

    ll ans = 0;
    for (auto x : s)
    {
        ll cnt1 = 0 , cnt2 = 0;
        for (size_t i = 1; i + x - 1 <= n; i++)
        {
            if (a[i + x - 1] - a[i - 1] == x)
                cnt1 ++;
        }
        for (size_t i = 1; i + k / x - 1 <= m; i++)
        {
            if (b[i + k / x - 1] - b[i - 1] == k / x)
                cnt2 ++;
        }
        ans += cnt2 * cnt1;
        
        if (x * x == k)
            break;
        cnt2 = cnt1 = 0;
        for (size_t i = 1; i + k / x - 1 <= n; i++)
        {
            if (a[i + k / x - 1] - a[i - 1] == k / x)
                cnt2 ++;
        }
        for (size_t i = 1; i + x - 1 <= m; i++)
        {
            if (b[i + x - 1] - b[i - 1] == x)
                cnt1 ++;
        }

        ans += cnt1 * cnt2;
    }
    cout << ans << endl;
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