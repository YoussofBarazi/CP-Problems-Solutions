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
    int n , time;
    cin >> n >> time;

    vi a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int yan = 0 , nathan = 0 , t = 0, i = 0;
    while (i < n && t + a[i] <= time) t += a[i] , yan ++ , i ++;
    i = n - 1;
    t = 0;
    while (i >= 0 && t + a[i] <= time) t += a[i] , nathan ++ , i --;
    
    string ans;
    if (yan > nathan)
        ans = "Yan";
    else if (nathan > yan)
        ans = "Nathan";
    else 
        ans = "Empate";

    cout << ans << endl;
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