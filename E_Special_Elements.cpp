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

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;
    map<int, int> freq;
    set<int> s;

    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
        freq[a[i]]++;
    }

    for (auto x : s)
    {
        int sum = 0, r = 0;

        for (int l = 0; l < n; l++)
        {
            while (r < n && sum < x)
                sum += a[r], r++;

            if (r - l > 1 && sum == x)
            {
                ans += freq[x];
                break;
            }

            sum -= a[l];
        }
    }

    cout << ans << endl;
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