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

int a[1000009];
int ps[1000009][10];
void get()
{
    for (size_t i = 1; i <= 1e6; i++)
    {
        int tmp = i;
        while (tmp >= 10)
        {
            int res = 1;
            while (tmp > 0)
            {
                if (tmp % 10 != 0)
                    res *= (tmp % 10);
                tmp /= 10;
            }
            tmp = res;
        }

        a[i] = tmp;
    }
    
    a[0] = 0;
    for (size_t k = 1; k < 10; k++)
    {
        int cnt = 0;
        for (size_t i = 1; i <= 1e6; i++)
        {
            if (a[i] == k) cnt ++;
            ps[i][k] = cnt;  
        }
    }
}

void solve()
{
    int l , r , k;
    cin >> l >> r >> k;

    cout << ps[r][k] - ps[l - 1][k] << endl;
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