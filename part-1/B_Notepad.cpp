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
    string s;
    cin >> n >> s;

    set <string> m;
    for (size_t i = 1; i < n; i++)
    {
        string tmp = "";
        tmp += s[i - 1];
        tmp += s[i];
        
        if (i + 1 < n && s[i] == s[i - 1] && s[i + 1] == s[i]) i ++;

        if (m.find(tmp) != m.end())
        {
            cout << "YES" << endl;
            return;
        }
        m.insert(tmp);
    }
    
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