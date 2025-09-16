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

    for (int num = 1; num <= n; num++)
    {
        int cnt = 0;
        set<vi> s;
        // cout << num << " is" << endl;
        for (int i = 1; i * i * i <= num; i++)
        {
            if (num % i == 0)
                for (int j = i; j * j <= num; j++)
                {
                    int x = num / i;
                    if (x % j == 0)
                    {
                        vector<int> v = {i, j, x / j};
                        sort(all(v));
                        s.insert(v);
                        // cout << i << " " << j << " " << x / j << endl;
                    }
                }
        }
        cout << s.size() << endl;
    }
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