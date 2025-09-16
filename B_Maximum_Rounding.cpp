#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
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
    string s;
    cin >> s;

    int n = s.size();
    vector<bool> used(n + 1, false);

    for (int i = n - 1; i >= 0;)
    {
        if (s[i] >= '5')
        {
            i--;
            while (i >= 0 && s[i] == '9')
                i--;

            if (i == -1)
            {
                cout << "1" + string(n, '0') << endl;
                return;
            }
            else
            {
                s[i] = s[i] + 1;
            }
            used[i + 1] = true;
            continue;
        }
        i--;
    }

    bool make_zero = false;
    for (int i = 0; i < n; i++)
    {
        make_zero |= used[i];
        if (make_zero)
            cout << "0";
        else
            cout << s[i];
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