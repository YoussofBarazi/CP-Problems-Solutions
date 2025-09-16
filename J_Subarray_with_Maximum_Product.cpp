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

const int N = 100009;

int mem[100000][97];
int n , x;
vi a;

int dp(int i , int res)
{
    if (i == n)
        return 0;
    if (mem[i][res] != 0) 
        return mem[i][res];

    int ans1 = dp(i + 1 , (res * a[i]) % x) + 1;
    int ans2 = dp(i + 1 , 1);

    mem[i][res] = min(ans1 , ans2);
    return mem[i][res];
}

void solve()
{
    cin >> n >> x;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < x; j++)
        {
            mem[i][j] = 0;
        }
    }
    
    a.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dp(0 , 1);
    int mx = 0 , length = n;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < x; j++)
        {
            if (mx < j && mem[i][j] > 0)
            {
                mx = j;
                length = mem[i][j]; 
            }
            else if (mx == j)
            {
                length = min(length , mem[i][j]);
            }
        }
    }
    
    cout << mx << " " << length << endl;
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