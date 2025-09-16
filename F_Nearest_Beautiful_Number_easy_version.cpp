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
    string n;
    int k;
    cin >> n >> k;
    string ans = "";
    if (k == 1)
    {
        for (size_t i = 1; i < 10; i++)
        {
            string tmp = "";
            for (size_t x = 0; x < n.size(); x++)
            {
                tmp += (i + '0');
            }
            if (n <= tmp)
            {
                ans = tmp;
                break;
            }
        }
    }
    else
    {
        ans = string(n.size(), '9');

        for (int y = 0; y <= 9; y++)
        {
            string ans2 = "";
            char x1 = n[0], x2 = char(y + '0');
            if (x2 > x1)
                swap(x1, x2);
            for (size_t i = 0; i < n.size(); i++)
            {
                if (n[i] == x1 || n[i] == x2)
                {
                    ans2 += n[i];
                }
                else
                {
                    ans2 += x2;
                }
            }

            int i = n.size() - 1;
            while (i >= 0)
            {
                ans2[i] = x1;
                if (ans2 >= n)
                {
                    ans = min(ans, ans2);
                }
                ans2[i] = x2;
                i--;
            }
        }
    }
    cout << ans << endl;
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