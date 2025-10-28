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
    int n , m;
    string s; 
    cin >> n >> m >> s;

    vi a(m);
    for (size_t i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    
    vector <vi> v(27);
    map <char , int> ans;

    for (size_t i = 0; i < n; i++)
    {
        ans[s[i]] ++;
        v[s[i] - 'a'].pb(i + 1);
    }
    
    for (size_t i = 0; i < m; i++)
    {
        for (auto j : ans)
        {
            int ind = LB(v[j.F - 'a'] , a[i]);
            if (ind < v[j.F - 'a'].size() && v[j.F - 'a'][ind] == a[i]) ind ++;
            ans[j.F] += ind;
        }
    }
    
    for (char i = 'a'; i <= 'z'; i++)
    {
        cout << ans[i] << " ";
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