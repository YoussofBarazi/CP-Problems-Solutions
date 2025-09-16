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
    int n, x;
    cin >> n >> x;

    vi freq(x + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        freq[a]++;
    }

    for (int i = 1; i < x; i++)
    {
        if (freq[i] % (i + 1))
        {
            cout << "No" << endl;
            return;
        }

        freq[i + 1] += freq[i] / (i + 1);
    }

    cout << "Yes" << endl;
}

int main()
{
    IOS;

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}