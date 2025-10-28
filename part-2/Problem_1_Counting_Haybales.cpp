#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

int pos[N] , n;

int calc_left (int x)
{
    int l = 0 , r = n - 1;

    while (l < r)
    {
        int mid = (l + r) / 2;

        if (pos[mid] >= x)
            r = mid;
        else 
            l = mid + 1;
    }

    return l;
}

int calc_right (int x)
{
    int l = 0 , r = n - 1;

    while (l < r)
    {
        int mid = (r + l + 1) / 2;

        if (pos[mid] <= x)
            l = mid;
        else 
            r = mid - 1;
    }

    return l;
}



void solve()
{
    int q ;
    cin >> n >> q ;

    for (int i = 0 ; i < n ; i ++)
        cin >> pos[i];

    sort(pos , pos + n);

    while (q --)
    {
        int l , r;
        cin >> l >> r;

        int ansL = calc_left(l) , ansR = calc_right(r);

        if (l <= pos[ansL] && pos[ansR] <= r)
            cout << ansR - ansL + 1 << endl;
        else 
            cout << 0 << endl;
    }
}

int main()
{
    freopen("haybales.in" , "r" , stdin);
    freopen("haybales.out" , "w" , stdout);

    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}