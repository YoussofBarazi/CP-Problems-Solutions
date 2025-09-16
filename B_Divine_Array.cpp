#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pi <int, int>
#define pl <ll, ll>
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

    vi a(n);
    map pi m; 
    vector <vi> ans;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]] ++;
    }
    ans.pb(a);

    while (true)
    {
        vi tmp = ans.back();
        map pi m2;
        for (size_t i = 0; i < n; i++)
        {
            tmp[i] = m[tmp[i]];
            m2[tmp[i]] ++;
        }
        m = m2;
        
        bool Continue = false;
        for (size_t i = 0; i < n; i++)
        {
            if (tmp[i] != ans.back()[i])
            {
                Continue = true;
                break;
            }
        }
        if (!Continue) break;
        ans.pb(tmp);        
    }

    int q , k , x;
    cin >> q;
    for (size_t i = 0; i < q; i++)
    {
        cin >> x >> k;
        cout << ans[min(int (ans.size()) - 1 , k)][x - 1] << endl;
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