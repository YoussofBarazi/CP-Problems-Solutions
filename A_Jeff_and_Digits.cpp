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
    int n;
    cin >> n;

    int cnt5 = 0, cnt0 = 0;
    while (n--)
    {
        int x;
        cin >> x;

        cnt0 += x == 0;
        cnt5 += x == 5;
    }

    if (cnt0 == 0)
        cout << -1 << endl;
    else if (cnt5 < 9)
        cout << 0 << endl;
    else
    {
        for (int i = 0; i < cnt5 - cnt5 % 9; i++)
            cout << 5;
        for (int i = 0; i < cnt0; i++)
            cout << 0;
    }
}

int main()
{
    IOS;

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}