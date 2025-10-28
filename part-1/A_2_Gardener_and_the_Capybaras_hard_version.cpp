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
    string s;
    cin >> s;

    string a = "" , b = "" , c = "";
    
    a += s[0];
    c += s.back();

    int x = 0;

    for (size_t i = 1; i < s.size() - 1; i++)
    {
        b += s[i];
        x = (s[i] == 'a')? i : x;
    }
    
    if ((a <= b && c <= b) || (b <= a && b <= c))
    {
        cout << a << " " << b << " " << c << endl;
    }
    else if (x)
    {
        cout << s.substr(0 , x) << " " << s[x] << " " << s.substr(x + 1 , s.size() - x - 1) << endl;
    }
    else 
    {
        cout << ":(" << endl;
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