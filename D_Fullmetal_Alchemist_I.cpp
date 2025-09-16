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
    string s1, s2;
    cin >> s1;
    if (n > 1)
    {
        cin >> s2;

        int ans = s1.size() + s2.size();
        string tmp;
        for (size_t i = 0; i < s1.size(); i++)
        {
            tmp += s1[i];
            if (s2.find(tmp) != string::npos)
            {
                ans = min(int(s1.size() + s2.size() - tmp.size()) , ans);
            }
        }

        tmp = "";
        for (size_t i = 0; i < s2.size(); i++)
        {
            tmp += s2[i];
            
            if (s1.find(tmp) != string::npos)
            {
                ans = min(int(s1.size() + s2.size() - tmp.size()) , ans);
            }
        }

        cout << ans << endl;
    }
    else
        cout << s1.size() << endl;
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