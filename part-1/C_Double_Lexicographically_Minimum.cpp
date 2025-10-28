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
    string s;
    cin >> s;

    int n = s.size();
    vi a(26 , 0);
    for (size_t i = 0; i < n; i++)
    {
        int ind = s[i] - 'a';
        a[ind]++;
    }

    int left = 0, right = n - 1;
    string ans(n , '.');

    for (size_t i = 0; i < 26; i++)
    {
        while (a[i] >= 2)
        {
            ans[left] = 'a' + i;
            ans[right] = 'a' + i;
            left ++;
            right --;
            a[i] -= 2;
        }

        if (a[i] > 0)
        {
            int x = i + 1;
            while (x < 26 && a[x] == 0)
            {
                x ++;
            }
            int x2 = 25;
            while (x2 >= 0 && a[x2] == 0)
            {
                x2 --;
            }

            if (x2 == x)
            {
                int tmp = 1;
                while (tmp <= (a[x] + 1) / 2)
                {
                    ans[left] = 'a' + x;
                    left ++;
                    tmp ++;
                }
                ans[left] = 'a' + i;
                left ++;
                while (tmp <= a[x])
                {
                    ans[left] = 'a' + x;
                    left ++;
                    tmp ++;
                }
                a[x] = 0;
            }
            else 
            {
                for (size_t j = 0; j < 26; j++)
                {
                    while (a[j] > 0 && i != j)
                    {
                        ans[left] = j + 'a';
                        left ++;
                        a[j] --;
                    }
                }
                ans[left] = i + 'a';
                left ++;
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