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

    vi a(1e5 + 1 , 0) , b(1e5 + 1 , 0);
    set <int> s1 , s2;
    for (size_t i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        a[x] ++;
        s1.insert(x);
    }
    ll ans1 = 0;
    for (auto x : s1)
    {
        if (k - x > 0) ans1 += a[x] * a[k - x];
        a[x] = 0;
    }

    for (size_t i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        b[x] ++;
        s2.insert(x);
    }
    ll ans2 = 0;
    for (auto x : s2)
    {
        if (k - x > 0) ans2 += b[x] * b[k - x];
        b[x] = 0;
    }

    string result;
    if (ans1 > ans2) result = "Mahmoud";
    else if (ans1 == ans2) result = "Draw";
    else result = "Bashar";

    cout << result << endl;  
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