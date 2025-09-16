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

    vector <string> s(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - 1; j++)
        {
            if (s[i][j] == '1' && s[i][j + 1] == '0' && s[i + 1][j] == '0')
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    
    cout << "YES" << endl;
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