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

multiset<int> L, R;

void solve()
{
    char t;
    int l, r;

    cin >> t >> l >> r;

    if (t == '+')
    {
        L.insert(l);
        R.insert(r);
    }
    else
    {
        L.erase(L.find(l));
        R.erase(R.find(r));
    }

    bool yes = false;

    if (L.size())
    {
        l = *R.begin(), r = *L.rbegin();

        yes = l < r;
    }

    if (yes)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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