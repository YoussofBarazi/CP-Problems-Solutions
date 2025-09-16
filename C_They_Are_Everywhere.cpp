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

    set <int> t;
    map <int , int> types;
    for (size_t i = 0; i < n; i++)
    {
        t.insert(s[i]);
    }
    
    int j = 0 , ans = n;
    for (int i = 0; i < n; i++)
    {
        while (j < n && types.size() != t.size()) types[s[j]] ++ , j ++;
        if (types.size() == t.size()) ans = min(ans , j - i);

        types[s[i]] --;
        if (types[s[i]] == 0) types.erase(s[i]);
    }
    
    cout << ans << endl;
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