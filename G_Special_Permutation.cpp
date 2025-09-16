#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
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

    if (n <= 3)
    {
        cout << -1 << endl;
        return;
    }

    for (int i = 2 ; i <= n ; i += 2)
        cout << i << " ";

    if (n % 2)
    {
        cout << n - 4 << " " << n << " " << n - 2 << " "; 

        for (int i = n - 6 ; i >= 1 ; i -= 2)
            cout << i << " ";
    }
    else 
    {
        cout << n - 3 << " " << n - 1 << " ";
        
        for (int i = n - 5 ; i >= 1 ; i -= 2)
            cout << i << " ";
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