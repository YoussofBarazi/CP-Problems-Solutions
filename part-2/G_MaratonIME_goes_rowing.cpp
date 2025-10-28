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
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend() 
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

    vi a , b;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A') a.pb(i);
        else b.pb(i);
    }
    
    if (a.size() != b.size())
    {
        cout << "Nao" << endl;
        return;
    }
    
    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i] > b[i])
        {
            cout << "Nao" << endl;
            return;
        }
    }
    
    cout << "Sim" << endl;
}

int main()
{
    IOS;

    int t = 1;
    //cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}