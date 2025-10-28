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

    int x = 1 , y = n * n;
    vi a[n];
    bool s1 = false , s2 = true;

    for (size_t i = 0; i < n; i++)
    {
        a[i].resize(n , 0);
    }
    
    for (size_t i = 0; i < n; i ++)
    {
        for (size_t j = 0; j < n && s2; j++)
        {
            if (s1) a[i][j] = x ++;
            else a[i][j] = y --;
            s1 = !s1;
        }
        
        for (int j = n - 1; j >= 0 && !s2; j --)
        {
            if (s1) a[i][j] = x ++;
            else a[i][j] = y --;
            s1 = !s1;
        }
        
        s2 = !s2;
    }
    
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
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