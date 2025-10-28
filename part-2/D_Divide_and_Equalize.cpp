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

const int N = 1000009;

int gpf[N];

void precalc()
{
    for (int i = 2; i <= N; i++)
        if (gpf[i] == 0)
            for (int j = i; j <= N; j += i)
                gpf[j] = i;
}

void solve()
{
    int n;
    cin >> n;

    map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        while (x > 1)
        {
            int g = gpf[x];
            while (x % g == 0)
                x /= g, freq[g]++;
        }
    }

    for (auto x : freq)
    {
        if (x.S % n)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main()
{
    IOS;

    precalc();

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}