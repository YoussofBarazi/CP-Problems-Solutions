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
    string s , s1 , s2;
    cin >> s;

    s1 = s2 = s;
    for (int i = 0; i < 10; i++)
    {
        if (s[i] == '?' && i % 2 == 0)
        {
            s1[i] = '1';
            s2[i] = '0';
        }
        else if (s[i] == '?')
        {
            s1[i] = '0';
            s2[i] = '1';
        }
    }
    
    int cnt1 = 0 , cnt2 = 0 , ans = 10;
    for (size_t i = 0; i < 10; i++)
    {
        if (s1[i] == '1' && i % 2 == 0)
        {
            cnt1 ++;
        }
        else if (s1[i] == '1')
        {
            cnt2 ++;
        }

        if (cnt1 > cnt2 && (cnt1 - cnt2) * 2 - i % 2 > 10 - i - 1)
        {
            ans = i + 1;
            break;
        }
        else if (cnt1 < cnt2 && (cnt2 - cnt1) * 2 - i % 2 > 10 - i - 1)
        {
            ans = i + 1;
            break;
        }
    }
    cnt1 = cnt2 = 0;
    for (int i = 0; i < 10; i++)
    {
        if (s2[i] == '1' && i % 2 == 0)
        {
            cnt1 ++;
        }
        else if (s2[i] == '1')
        {
            cnt2 ++;
        }

        if (cnt1 > cnt2 && (cnt1 - cnt2) * 2 - i % 2 > 10 - i - 1)
        {
            ans = min (i + 1 ,ans);
            break;
        }
        else if (cnt1 < cnt2 && (cnt2 - cnt1) * 2 - i % 2 > 10 - i - 1)
        {
            ans = min (i + 1 ,ans);
            break;
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