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

    string s1 = ".", s2;
    string t;
    for (size_t i = 0; i < 2 * (n - 1); i++)
    {
        cin >> t;

        if (t.size() == n - 1) 
        {
            if (s1 == ".")
                s1 = t;
            else 
                s2 = t;
        }
    }
    
    bool f = true;
    for (size_t i = 1; i < s1.size(); i++)
    {
        if (s1[i] != s2[i - 1])
            f = false;
    }
    
    if (f)
    {
        s1 += s2.back();
        string t = s1;
        reverse(t.begin() , t.end());

        if (s1 == t)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
    else 
    {
        s2 += s1.back();
        string t = s2;
        reverse(t.begin() , t.end());

        if (s2 == t)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
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