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
    int a , b;
    string s;
    cin >> a >> b >> s;

    int i = 0 , j = s.size() - 1;
    while (i < s.size() && s[i] == '0') i ++;
    while (j >= 0 && s[j] == '0') j --;
    ll ans = (i != s.size())? a : 0;
    for (; i < j; i++)
    {
        int cnt = 0;
        if (s[i] != s[i + 1] && s[i] == '1')
        {
            while (i < j && s[i + 1] == '0') cnt ++ , i ++;

            ans += min(a , cnt * b);
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