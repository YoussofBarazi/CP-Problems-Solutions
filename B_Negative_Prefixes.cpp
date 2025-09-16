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

    vi a(n) , l(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    priority_queue <int> q;
    for (size_t i = 0; i < n; i++)
    {
        cin >> l[i];
    
        if (!l[i])
        {
            q.push(a[i]);
        }
    }
    
    for (size_t i = 0; i < n; i++)
    {
        if (!l[i])
        {
            a[i] = q.top();
            q.pop();
        }
        cout << a[i] << " ";
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