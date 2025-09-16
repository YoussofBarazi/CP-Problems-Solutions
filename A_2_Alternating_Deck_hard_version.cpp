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
    ll n;
    cin >> n;

    n --;
    ll Walice = 1 , Balice = 0 , Wbob = 0 , Bbob = 0;
    ll x = 2;
    bool color = true;
    
    while (n > 0)
    {
        for (int i = 1; i <= min(x * 2 + 1 , n); i++)
        {
            if (color) Bbob ++;
            else Wbob ++;
            color = !color;
        }
        n -= x * 2 + 1;
        x += 2;

        for (int i = 1; i <= min(x * 2 + 1 , n); i++)
        {
            if (color) Balice ++;
            else Walice ++;
            color = !color;
        }
        n -= x * 2 + 1;
        x += 2;
    }
    cout << Walice << " " << Balice << " " << Wbob << " " << Bbob << endl;
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