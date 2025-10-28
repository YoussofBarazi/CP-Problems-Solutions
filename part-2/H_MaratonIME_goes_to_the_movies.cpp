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

    vi a(n) , b(n) , c(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    double yan = 0 , IME = 0;
    for (size_t i = 0; i < n; i++)
    {
        yan += (a[i] - b[i]) * (a[i] - b[i]); 
    }
    yan = sqrt(yan);

    for (size_t i = 0; i < n; i++)
    {
        IME += (a[i] - c[i]) * (a[i] - c[i]); 
    }
    IME = sqrt(IME);

    if (IME >= yan)
        cout << "Yan";
    else 
        cout << "MaratonIME";
    cout << endl;
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