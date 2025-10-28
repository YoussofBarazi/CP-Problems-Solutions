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
    double x1 , y1 , x2 , y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double x3 , y3 , x4 , y4;
    cin >> x3 >> y3 >> x4 >> y4;

    double d1 = sqrt(pow(x1 - x2 , 2) + pow(y1 - y2 , 2));
    double d2 = sqrt(pow(x3 - x4 , 2) + pow(y3 - y4 , 2));
    double d3 = sqrt(pow(x1 - x3 , 2) + pow(y1 - y3 , 2));

    if (d1 + d2 > d3)
    {
        cout << "Yes" << endl;
    }
    else 
    {
        cout << "No" << endl;
    }
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