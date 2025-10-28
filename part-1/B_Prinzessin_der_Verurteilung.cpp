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
    cin >> n;

    string s;
    cin >> s;

    string x = "a";

    while (true)
    {
        if (s.find(x) == string::npos)
        {
            cout << x << endl;
            return;
        }

        int i = x.size() - 1;
        while (i >= 0 && x[i] == 'z') i --;
        if (i == -1)
        {
            x = string(x.size() + 1 , 'a');
        }
        else 
        {
            x[i] ++;
            for (size_t k = i + 1; k < x.size(); k++)
            {
                x[k] = 'a';
            }
        }
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