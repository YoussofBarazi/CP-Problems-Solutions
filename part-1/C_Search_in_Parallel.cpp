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
    int n , s1 , s2;
    cin >> n >> s1 >> s2;

    vector <pair <int , int>> v(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> v[i].F;
        v[i].S = i + 1;
    }
    sort(allrev(v));

    vector <int> a , b;
    for (size_t i = 0; i < n; i++)
    {   
        if ((a.size() + 1) * s1 < (b.size() + 1) * s2)
        {
            a.pb(v[i].S);
        }
        else 
        {
            b.pb(v[i].S);
        }        
    }
    
    cout << a.size() << " ";
    for (size_t i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << b.size() << " ";
    for (size_t i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
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