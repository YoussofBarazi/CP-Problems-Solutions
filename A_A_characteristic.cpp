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
    int n , k;
    cin >> n >> k;

    int pos = n , neg = 0;
    if (k < n * (n - 1) / 2) neg ++ , pos --;

    int cnt = 1000;
    while (cnt > 0)
    {
        if (neg * (neg - 1) / 2 + pos * (pos - 1) / 2 != k)
        {
            pos --;
            neg ++;
        }
        cnt --;
    }

    if (neg * (neg - 1) / 2 + pos * (pos - 1) / 2 != k)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for (size_t i = 0; i < neg; i++)
    {
        cout << -1 << " ";
    }
    for (size_t i = 0; i < pos; i++)
    {
        cout << 1 << " ";
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