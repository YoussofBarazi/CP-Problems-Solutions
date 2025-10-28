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
    string s;
    cin >> s;

    map <int , int> m1 , m2;
    for (size_t i = 0; i < n; i++)
    {
        m2[s[i]] ++;
    }
    
    int ans = 0;
    for (size_t i = 0; i < n; i++)
    {
        m1[s[i]] ++;
        m2[s[i]] --;
        if (m2[s[i]] == 0)
        {
            m2.erase(s[i]);
        }

        ans = max(ans , int(m2.size() + m1.size()));
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