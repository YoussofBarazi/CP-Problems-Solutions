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
    int n;
    cin >> n;

    set <int> s;
    vi a;
    int neg = 0 , pos = 0;
    for (size_t i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        if (x > 0)
            pos ++; 
        else if (x < 0)
            neg ++;
        else if (i - neg - pos > 2)
            continue;

        a.pb(x);
        s.insert(x);
    }
    
    if (pos > 2 || neg > 2)
    {
        cout << "NO" << endl;
        return;
    }

    for (size_t i = 0; i < a.size(); i++)
    {
        for (size_t j = i + 1; j < a.size(); j++)
        {
            for (size_t k = j + 1; k < a.size(); k++)
            {
                if (s.find(a[i] + a[j] + a[k]) == s.end())
                {
                    cout << "NO" << endl;
                    return;
                }
            }   
        }
    }
    
    cout << "YES" << endl;
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