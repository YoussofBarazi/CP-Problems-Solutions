#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
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

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(all(a));

    vector <int> X;

    int t1 = a[0] , t2 = a.back();   
    while (t1 != t2)
    {
        if (t1 % 2)
        {
            t1 = (t1 + 1) / 2;
            t2 = (t2 + 1) / 2;
            X.pb(1);
        }
        else 
        {
            t1 /= 2;
            t2 /= 2;
            X.pb(0);
        }
    }


    cout << X.size() << endl;

    if (X.size() > n || X.size() == 0)
        return;

    for (auto x : X)
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