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
    cin >> a >> b;
    int n = a + b;
    string s;
    cin >> s;

    for (size_t i = 0; i < n; i++)
    {
        if (s[i] == '1') b --;
        else if (s[i] == '0') a --;
    }
    
    for (size_t i = 0; i < n / 2; i++)
    {
        if (s[i] == s[n - i - 1])
        {
            continue;
        }
        if (s[i] != '?' && s[n - i - 1] != '?')
        {
            cout << -1 << endl;
            return;
        }
        if (s[i] == '?')
        {
            if (s[n - i - 1] == '1') s[i] = '1' , b --;
            else s[i] = '0' , a --;
        }
        else if (s[i] == '1')
        {
            b --;
            s[n - i - 1] = '1';
        }
        else 
        {
            a --;
            s[n - i - 1] = '0';
        }
    }
    
    for (size_t i = 0; i < n / 2; i++)
    {
        if (s[i] == s[n - i - 1] && s[n - i - 1] == '?')
        {
            if (b >= 2) b -= 2 , s[i] = s[n - i - 1] = '1';
            else a -= 2 , s[i] = s[n - i - 1] = '0';
        }
    }
    if (n % 2)
    {
        if (s[n / 2] == '?')
        {
            if (a > 0) s[n / 2] = '0' , a --;
            else s[n / 2] = '1' , b --;
        }
    }
    string x = s;
    reverse(x.begin() , x.end());
    if (x != s || a || b)
    {
        cout << -1 << endl;
    }
    else 
    {
        cout << s << endl;
    }
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