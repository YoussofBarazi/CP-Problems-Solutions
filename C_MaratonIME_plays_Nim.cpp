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
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend() 
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

void solve()
{
    int x , y;
    cin >> x >> y;

    while (x + y > 0)
    {
        int i , k;
        if (x > y)
            i = 1 , k = abs(x - y) , x -= k;
        else 
            i = 2 , k = abs(x - y) , y -= k;

        cout << i << " " << k << endl;

        cin >> i >> k;

        if (i == 1) x -= k;
        else y -= k;
    }
    cout << endl;
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