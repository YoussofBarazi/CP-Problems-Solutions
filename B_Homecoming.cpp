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
    int a , b , p;
    string s;
    cin >> a >> b >> p;
    cin >> s;

    int cnt = 1 , cost = 0;
    int i = s.size() - 1;
    
    while (i > 0 && s[i] == s[i - 1]) i --;

    if (i != s.size() - 1)
        cost += (s.back() == 'A')? a : b;
    
    if (cost > p)
    {
        cout << s.size() << endl;
        return;
    }

    for (;i >= 1; i --)
    {
        if (s[i] != s[i - 1])
        {
            cost += (s[i - 1] == 'A')? a : b;
        }
        if (cost > p)
        {
            cout << i + 1 << endl;
            return;
        }
    }
    
    cout << 1 <<endl;
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