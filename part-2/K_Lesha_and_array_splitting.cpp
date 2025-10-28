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
    int n;
    cin >> n;

    vi a(n);
    int sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    
    if (sum != 0)
    {
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
    }
    else 
    {
        int i = 0;
        while (i < n && a[i] == 0) i ++;
        if (i == n)
        {
            cout << "NO" << endl;
            return;
        }
        else
        {
            cout << "YES" << endl;
            if (i == 0)
            {
                cout << 2 << endl;
                cout << 1 << " " << i + 1 << endl;
                cout << 2 << " " << n << endl; 
            }
            else if (i == n - 1)
            {
                cout << 2 << endl;
                cout << 1 << " " << i << endl;
                cout << n << " " << n << endl;
            }
            else 
            {
                cout << 2 << endl;
                cout << 1 << " " << i << endl;
                cout << i + 1 << " " << n << endl;
            }
        }
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