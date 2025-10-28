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

    int x;
    vi a , freq(10 , 0);
    for (size_t i = 0; i < n; i++)
    {
        cin >> x;

        if (freq[x % 10] > 3)
            continue;
        a.pb(x % 10);
        freq[x % 10] ++;
    }
    
    for (size_t i = 0; i < a.size(); i++)
    {
        for (size_t j = i + 1; j < a.size(); j++)
        {
            for (size_t k = j + 1; k < a.size(); k++)
            {
                if ((a[i] + a[j] + a[k]) % 10 == 3)
                {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }
    
    cout << "NO" << endl;
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