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
    int n;
    string a , b;
    cin >> n >> a >> b;

    int i = 0 , j = n - 1;
    vi swaps;
    int first_swaps = 0 , cur = n - 1;
    while (cur > 0)
    {
        char x = a[j];
        if ((swaps.size() - first_swaps) % 2)
        {
            x = (x == '1')? '0' : '1';
        }

        if (x != b[cur])
        {
            x = a[i];
            if ((swaps.size() - first_swaps) % 2)
            {
                x = (x == '1')? '0' : '1';
            }

            if (x == b[cur])
            {
                swaps.pb(1);
                first_swaps ++;
                swaps.pb(cur + 1);
                swap (i , j);
                j += (i < j)? -1 : 1;
            }
            else
            {
                swaps.pb(cur + 1);
                swap(i , j);
                j += (i < j)? -1 : 1;
            }   
        }
        else
        {
            if (j >= i) j --;
            else j ++;
        }
        cur --;
    }

    if ((swaps.size() - first_swaps) % 2)
    {
        a[j] = (a[j] == '1')? '0' : '1';
    }
    if (a[j] != b[cur])
    {
        swaps.pb(1);
    }

    cout << swaps.size();
    for (size_t i = 0; i < swaps.size(); i++)
    {
        cout << " " << swaps[i];
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