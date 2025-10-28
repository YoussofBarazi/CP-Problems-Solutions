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

    vi a(n);
    ll sum = 0;
    bool ok = true;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    while (n > 0 && a[n - 1] == 0) n --;

    for (size_t i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            if (sum < abs(a[i]))
                ok = false;
            else if (sum == abs(a[i]) && i != n - 1)
                ok = false;
            else 
                sum += a[i];
        }
        else 
        {
            sum += a[i];
        }
    }
    
    if (sum > 0 || (a[0] == 0 && n != 0) || a.back() > 0) ok = false;

    cout << ((!ok)? "No" : "Yes") << endl;
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