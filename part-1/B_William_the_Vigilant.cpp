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
    int n , q;
    cin >> n >> q;

    string s;
    cin >> s;

    int cnt = 0;
    for (size_t i = 0; i + 2 < n; i++)
    {
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
        {
            cnt ++;
        }
    }
    
    for (size_t i = 0; i < q; i++)
    {
        int pos; char c;
        cin >> pos >> c;
        pos --;

        if (c != s[pos])
        {
            if (s[pos] == 'a' && pos + 2 < n &&s[pos + 1] == 'b' && s[pos + 2] == 'c')
            {
                cnt --;
            }
            else if (s[pos] == 'b' && pos - 1 >= 0 && s[pos - 1] == 'a' && pos + 1 < n && s[pos + 1] == 'c')
            {
                cnt --;
            }
            else if (s[pos] == 'c' && pos - 2 >= 0 && s[pos - 1] == 'b' && s[pos - 2] == 'a')
            {
                cnt --;
            }

            s[pos] = c;

            if (s[pos] == 'a' && pos + 2 < n &&s[pos + 1] == 'b' && s[pos + 2] == 'c')
            {
                cnt ++;
            }
            else if (s[pos] == 'b' && pos - 1 >= 0 && s[pos - 1] == 'a' && pos + 1 < n && s[pos + 1] == 'c')
            {
                cnt ++;
            }
            else if (s[pos] == 'c' && pos - 2 >= 0 && s[pos - 1] == 'b' && s[pos - 2] == 'a')
            {
                cnt ++;
            }
        }

        cout << cnt << endl;
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