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

int get_mex(vi &a)
{
    set<int> s;

    for (size_t i = 0; i < a.size(); i++)
    {
        s.insert(a[i]);
    }
    
    int mex = 0;
    for (auto x : s)
    {
        if (x == mex)
            mex++;
    }

    return mex;
}

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    map<int, int> freq;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }

    int mex = get_mex(a);

    int l = n - 1, r = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == mex + 1)
            l = min(l, i), r = max(r, i);
    }

    for (size_t i = l; i <= r; i++)
    {
        freq[a[i]]--;
        a[i] = mex;
        freq[a[i]]++;
    }

    for (size_t i = 0; i < n; i++)
    {
        if (freq[a[i]] > 1 || a[i] > mex)
        {
            a[i] = mex;
            break;
        }
    }

    int new_mex = get_mex(a);

    cout << ((new_mex == mex + 1) ? "YES" : "NO") << endl;
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