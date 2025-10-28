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

void solve()
{
    ll n, p;
    cin >> n >> p;

    vector<pl> a(n);
    for (auto &x : a)
    {
        cin >> x.F >> x.S;
    }

    for (auto x : a)
    {
        if (x.F > x.S)
        {
            if (x.F <= p)
                p += x.F;
            else if (x.S <= p)
                p += x.S;
            else
            {
                cout << "N" << endl;
                return;
            }
        }
        else
        {
            if (x.S <= p)
                p += x.S;
            else if (x.F <= p)
                p += x.F;
            else
            {
                cout << "N" << endl;
                return;
            }
        }
    }

    cout << "S" << endl;
}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}