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
    int n; string s;
    cin >> n >> s;

    vector <vi> a , x; 

    for (size_t i = 'a'; i <= 'z'; i++)
    {
        a.pb({});
        a[i - 'a'].resize(n + 1 , 0);
        a[i - 'a'][0] = 0;
        int cnt = 0;
        for (size_t j = 0; j < n; j++)
        {
            cnt += (s[j] == char(i));
            a[i - 'a'][j + 1] = cnt;
        }
    }
    
    x.resize(26);
    for (size_t i = 'a'; i <= 'z'; i++)
    {
        x[i - 'a'].resize(n + 1);
        for (int m = 1; m <= n; m++)
        {
            int k = 0 , ans = 0;
            for (int j = 0; j < n; j++)
            {
                while (k < n && k - j + 1 - (a[i - 'a'][k + 1] - a[i - 'a'][j]) <= m) k ++;
                ans = max (ans , k - j);
            }
            x[i - 'a'][m] = ans;
        }   
    }
    

    int q;
    cin >> q;

    for (size_t i = 0; i < q; i++)
    {
        int m; char c;
        cin >> m >> c;

        cout << x[c - 'a'][m] << endl;
    }
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