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

    vector <pi> even , odd;
    for (size_t i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x % 2) odd.push_back({x , i + 1});
        else even.pb({x , i + 1});
    }
    
    if (odd.size() == 0 || (n == 3 && odd.size() == 2))
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if (odd.size() >= 3)
    {
        cout << odd[0].S << " " << odd[1].S << " " << odd[2].S << endl;
    }
    else 
    {
        cout << odd[0].S << " " << even[0].S << " " << even[1].S << endl;
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