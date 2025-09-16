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

    vi a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int i = 0, j = n - 1;
    int alice = 0, bob = 0, moves = 0;
    int tmp = 0 , cur = 0;
    while (i <= j)
    {
        if (tmp >= cur)
        {   
            while (i <= j && cur <= tmp)
            {
                alice += a[i];
                cur += a[i];
                i++;
            }
            tmp = cur;
            cur = 0;
            moves ++;
        }
        if (tmp >= cur && i <= j)
        {    
            while (i <= j && tmp >= cur)
            {
                bob += a[j];
                cur += a[j];
                j--;
            }
            moves ++;
            tmp = cur;
            cur = 0;
        }
    }
    cout << moves << " " << alice << " " << bob << endl;
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