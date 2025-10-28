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

    vector<string> s(n);
    map<string, int> exist;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 0; i < n; i++)
    {
        string tmp = s[i];
        bool push = true;
        for (int j = int(s[i].size() - 1); j >= 0; j--)
        {
            tmp.pop_back();
            tmp = s[i][j] + tmp;

            if (exist.find(tmp) != exist.end())
            {
                push = false;
                break;
            }
        }

        if (push)
            exist[s[i]]++;
    }

    cout << exist.size() << endl;
}

int main()
{
    IOS;

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}