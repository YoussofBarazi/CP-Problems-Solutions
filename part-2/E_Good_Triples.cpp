#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 10000009;

ll num[N];

void precalc(int n)
{        
    for (int i = 0 ; i <= n ; i ++)
    {
        num[i] ++;

        int t = i;

        while (t > 0)
        {
            int d = t % 10 + 2;

            ll w = d * (d - 1) / 2;

            num[i] *= w;

            t /= 10;
        }
    }
}


void solve()
{
    int n;
    cin >> n;

    cout << num[n] << endl;
}

int main()
{
    IOS;

    precalc(1e7);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}