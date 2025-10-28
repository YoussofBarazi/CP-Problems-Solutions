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
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;

    int cnt0 = 0;
    while (n0 > 0 && cnt0 <= n0)
    {
        cout << '0';
        cnt0++;
    }

    if (n1 > 0 && n1 % 2)
    {
        int cnt1 = 1;

        if (n0 == 0)
        {
            cout << "01";
        }
        else
            cout << '1';

        while (cnt1 < n1)
        {
            cout << ((cnt1 % 2) ? '0' : '1');
            cnt1++;
        }
    }

    if (n2 > 0)
    {
        int cnt2 = 1;

        if (n1 > 0 && n1 % 2)
            cout << '1';
        else
            cout << "11";

        while (cnt2 < n2)
        {
            cout << '1';
            cnt2++;
        }
    }

    if (n1 > 0 && n1 % 2 == 0)
    {
        int cnt1 = 1 , i = 0;

        if (n2 > 0 && n0 > 0)
            cnt1 ++;

        if (n2 > 0)
        {
            while (cnt1 <= n1)
            {
                cout << ((i % 2 == 0) ? '0' : '1');
                cnt1++;
                i ++;
            }
        }
        else if (n0 > 0)
        {
            while (cnt1 <= n1)
            {
                cout << ((i % 2) ? '0' : '1');
                cnt1++;
                i ++;
            }
        }
        else
        {
            cout << "01";
            while (cnt1 < n1)
            {
                cout << ((cnt1 % 2) ? '0' : '1');
                cnt1++;
            }
        }
    }

    cout << endl;
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