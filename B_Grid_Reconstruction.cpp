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

    vi ans[2];
    ans[0].resize(n);
    ans[1].resize(n); 
    
    int x = 2 * n , y = 2;
    
    for (size_t i = 0; i < n; i++)
    {
        if (i % 2 == 0) 
        {
            cout << x << " ";
            x -= 2;
        }
        else
        {
            cout << y << " ";
            y += 2;
        }
    }
    x = n + 1 , y = 1;
    cout << endl;
    for (size_t i = 0; i < n; i++)
    {
        if (i % 2 != 0) 
        {
            cout << x << " ";
            x += 2;
        }
        else
        {
            cout << y << " ";
            y += 2;
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