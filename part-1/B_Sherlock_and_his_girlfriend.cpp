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

    vector<int> isPrime(n + 2, 1);
    int color = 1;

    for (int i = 2; i <= n + 1; i++)
    {
        if (isPrime[i] == 1)
        {
            for (int j = i * 2; j <= n + 1; j += i)
            {
                isPrime[j] = 2;
            }
        }
    }

    if (n > 2)
        cout << 2 << endl;
    else
        cout << 1 << endl;

    for (int i = 2; i <= n + 1; i++)
    {
        cout << isPrime[i] << " ";
    }
    cout << endl;
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