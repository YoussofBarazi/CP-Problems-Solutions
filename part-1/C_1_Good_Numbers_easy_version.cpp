#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define inf INT_MAX
#define INF LONG_MAX
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

long long POW(long long x, long long y)
{

    if (y == 0)
        return 1;
    if (y == 1)
        return x;

    long long ans = POW(x, y / 2);

    if (y & 1)
        return ans * ans * x;
    return ans * ans;
}

vl a(39);
void get()
{
    for (size_t i = 0; i <= 38; i++)
    {
        a[i] = POW(3 , i);
    }
}

ll n;
int cnt = 0;
map <pair <int , ll> , ll> m;

ll O_O (int i , ll res)
{
    if (res >= n)
    {
        return res;
    }
    else if (i > cnt)
    {
        return 1e16;
    }
    else if (m[{i , res}])
    {
        return m[{i , res}];
    }

    ll ans1 = O_O (i + 1 , res + a[i]);
    ll ans2 = O_O (i + 1 , res);

    m[{i , res}] = min (ans1 , ans2);
    
    return min(ans1 , ans2);
}

void solve()
{
    cin >> n;
    
    ll tmp = n;

    while (tmp > 0)
    {
        cnt ++;
        tmp /= 3;
    }

    ll ans = O_O (0 , 0);
    cout << ans << endl;
 
    m.clear();
}

int main()
{
    IOS;

    get();

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}