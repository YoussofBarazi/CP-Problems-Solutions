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

    int length = 0;
    vi a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > length && a[i] != 1)
            length ++;
    }
    
    vi ans(n);
    ans[n - 1] = max(length , 1);
    for (int i = n - 2; i >= 0; i--)
    {
        int &p = ans[i];
        length --;

        if (i - length >= 0 && a[i - length] > length)
            length ++;
        
        p = max(length , 1);
    }

    for (auto x : ans)
        cout << x << " ";
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